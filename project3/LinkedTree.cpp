#include "LinkedTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

static const std::string SEPARATOR = "-------------------";


// constructor / destructor

LinkedTree::LinkedTree() : root(nullptr) {}

LinkedTree::~LinkedTree() {
    destroyTree(root);
}

// recursively deletes every node in the subtree rooted at node
void LinkedTree::destroyTree(TreeNode* node) {
    if (!node) return;
    for (TreeNode* child : node->children)
        destroyTree(child);
    delete node;
}


// file parsing helper (free function)


// splits a raw file line into its four logical fields.
// tries tab-separated format first (as specified), then falls back to
// space-separated so the program works with either delimiter.
static void parseLine(const std::string& line,
                      int& level, int& pos,
                      std::string& edge, std::string& content) {
    level = 0; pos = 0; edge = ""; content = "";

    std::vector<std::string> tokens;
    {
        std::stringstream ss(line);
        std::string tok;
        while (std::getline(ss, tok, '\t'))
            tokens.push_back(tok);
    }

    if (tokens.size() >= 3) {
        try {
            level = std::stoi(tokens[0]);
            pos   = std::stoi(tokens[1]);
        } catch (...) { return; }

        // Root node (level 0) has no edge label -> 3 fields others have 4
        if (level == 0 || tokens.size() == 3) {
            content = tokens[2];
            for (size_t i = 3; i < tokens.size(); i++)
                content += "\t" + tokens[i];
        } else {
            edge    = tokens[2];
            content = tokens[3];
            for (size_t i = 4; i < tokens.size(); i++)
                content += "\t" + tokens[i];
        }
        return;
    }

    // space-separated fallback 
    // format: level pos [edgeWord] content...
    // edge label is a single word 
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string w;
    while (iss >> w) words.push_back(w);

    if (words.size() < 3) return;

    try {
        level = std::stoi(words[0]);
        pos   = std::stoi(words[1]);
    } catch (...) { return; }

    size_t contentStart;
    if (level == 0) {
        edge         = "";
        contentStart = 2;
    } else {
        edge         = words[2];
        contentStart = 3;
    }

    for (size_t i = contentStart; i < words.size(); i++) {
        if (i > contentStart) content += " ";
        content += words[i];
    }
}


// Tree construction


// reads the input file, creates TreeNode objects, sorts them by preorder
// position, and links them into the parent-child hierarchy using a
// "last node seen at each level" map 
void LinkedTree::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'.\n";
        return;
    }

    std::vector<TreeNode*> nodeList;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        int lev = 0, p = 0;
        std::string edge, content;
        parseLine(line, lev, p, edge, content);

        if (content.empty()) continue;

        TreeNode* node = new TreeNode(content, edge, lev, p);
        nodeList.push_back(node);
        nodesByPosition[p] = node;
    }

    if (nodeList.empty()) {
        std::cerr << "Error: No valid nodes found in file.\n";
        return;
    }

    // sort by preorder position so we can reconstruct parent links in one pass
    std::sort(nodeList.begin(), nodeList.end(),
              [](TreeNode* a, TreeNode* b) {
                  return a->preorderPos < b->preorderPos;
              });

    root = nodeList[0];

    // lastAtLevel[n] = most recently visited node at depth n.
    // when a node at level L is processed, its parent is lastAtLevel[L-1].
    std::map<int, TreeNode*> lastAtLevel;
    lastAtLevel[root->level] = root;

    for (size_t i = 1; i < nodeList.size(); i++) {
        TreeNode* node  = nodeList[i];
        int parentLevel = node->level - 1;

        if (lastAtLevel.count(parentLevel)) {
            TreeNode* parent = lastAtLevel[parentLevel];
            node->parent     = parent;
            parent->children.push_back(node);
        }

        lastAtLevel[node->level] = node;
    }
}


// preorder traversal: prints each node with level*2 leading dashes and edge label
void LinkedTree::printVisualization(TreeNode* node, std::ostream& out) {
    if (node->level == 0) {
        // root has no incoming edge
        out << node->content << "\n";
    } else {
        std::string dashes(node->level * 2, '-');
        out << dashes << "[" << node->edgeLabel << "] " << node->content << "\n";
    }
    for (TreeNode* child : node->children)
        printVisualization(child, out);
}

// adds every internal (non-leaf) node to result in preorder
void LinkedTree::collectInternalNodes(TreeNode* node, std::vector<TreeNode*>& result) {
    if (!node->children.empty()) {
        result.push_back(node);
        for (TreeNode* child : node->children)
            collectInternalNodes(child, result);
    }
}

// adds every external (leaf) node to result in preorder
void LinkedTree::collectExternalNodes(TreeNode* node, std::vector<TreeNode*>& result) {
    if (node->children.empty()) {
        result.push_back(node);
    } else {
        for (TreeNode* child : node->children)
            collectExternalNodes(child, result);
    }
}

// returns the number of edges on the longest path from node down to a leaf
int LinkedTree::computeHeight(TreeNode* node) {
    if (node->children.empty()) return 0;
    int maxH = 0;
    for (TreeNode* child : node->children)
        maxH = std::max(maxH, computeHeight(child));
    return 1 + maxH;
}



// returns true if no node in the subtree has more than 2 children
bool LinkedTree::checkBinaryTree(TreeNode* node) {
    if (node->children.size() > 2) return false;
    for (TreeNode* child : node->children)
        if (!checkBinaryTree(child)) return false;
    return true;
}

// returns true if every internal node has exactly 2 children
bool LinkedTree::checkProperBinaryTree(TreeNode* node) {
    if (!node->children.empty() && node->children.size() != 2) return false;
    for (TreeNode* child : node->children)
        if (!checkProperBinaryTree(child)) return false;
    return true;
}

// returns true if all leaves reside at depth == treeHeight
bool LinkedTree::checkPerfectBinaryTree(TreeNode* node, int treeHeight, int currentLevel) {
    if (node->children.empty())
        return currentLevel == treeHeight;
    if (node->children.size() != 2) return false;
    for (TreeNode* child : node->children)
        if (!checkPerfectBinaryTree(child, treeHeight, currentLevel + 1)) return false;
    return true;
}

// returns the subtree height when height-balanced (|leftH - rightH| <= 1 everywhere),
// or -1 if any node violates the balance condition.
int LinkedTree::computeBalancedHeight(TreeNode* node) {
    if (node->children.empty()) return 0;

    // children[0] is left, children[1] is right; absent subtree counts as height 0
    int leftH  = computeBalancedHeight(node->children[0]);
    int rightH = (node->children.size() >= 2)
                     ? computeBalancedHeight(node->children[1]) : 0;

    if (leftH == -1 || rightH == -1)   return -1;
    if (std::abs(leftH - rightH) > 1)  return -1;
    return 1 + std::max(leftH, rightH);
}


// output file generation


void LinkedTree::generateOutputFile(const std::string& outputFilename) {
    if (!root) {
        std::cerr << "Error: Tree is empty. Cannot generate output.\n";
        return;
    }

    std::ofstream out(outputFilename);
    if (!out.is_open()) {
        std::cerr << "Error: Could not create '" << outputFilename << "'.\n";
        return;
    }

    printVisualization(root, out);
    out << "\n";

    out << SEPARATOR << "\n";
    out << "Tree Properties\n";
    out << SEPARATOR << "\n";
    out << "\n";

    std::vector<TreeNode*> internalNodes, externalNodes;
    collectInternalNodes(root, internalNodes);
    collectExternalNodes(root, externalNodes);
    int treeHeight = computeHeight(root);

    out << "Root: "                     << root->content        << "\n";
    out << "Number of internal nodes: " << internalNodes.size() << "\n";
    out << "Number of external nodes: " << externalNodes.size() << "\n";
    out << "Tree Height: "              << treeHeight           << "\n";
    out << "\n";

    out << "Internal Nodes:\n";
    for (TreeNode* node : internalNodes)
        out << node->content << "\n";
    out << "\n";

    out << "External Nodes:\n";
    for (TreeNode* node : externalNodes)
        out << node->content << "\n";
    out << "\n";

    out << SEPARATOR << "\n";
    out << "Binary Tree Properties\n";
    out << SEPARATOR << "\n";
    out << "\n";

    bool isBinary = checkBinaryTree(root);
    out << "Binary Tree: " << (isBinary ? "Yes" : "No") << "\n";

    if (isBinary) {
        bool isProper   = checkProperBinaryTree(root);
        bool isPerfect  = checkPerfectBinaryTree(root, treeHeight, 0);
        bool isBalanced = (computeBalancedHeight(root) != -1);

        out << "Proper Tree: "   << (isProper   ? "Yes" : "No") << "\n";
        out << "Perfect Tree: "  << (isPerfect  ? "Yes" : "No") << "\n";
        out << "Balanced Tree: " << (isBalanced ? "Yes" : "No") << "\n";
    }

    out.close();
    std::cout << "Output written to '" << outputFilename << "'.\n";
}


// lets the user type a preorder position to inspect a node's content,
// ancestor (parent), descendant (first child), and sibling.
// loops until the user types "exit".
void LinkedTree::interactiveExplore() {
    std::string input;

    while (true) {
        std::cout << "\nWhich node would you like to explore (enter position or \"exit\"):\n";
        std::cin >> input;

        // exit condition 
        if (input == "exit") {
            std::cout << "Goodbye!\n";
            break;
        }

        // validate: must be a non-empty string of digit characters
        bool allDigits = !input.empty();
        for (char c : input)
            if (!std::isdigit(static_cast<unsigned char>(c))) { allDigits = false; break; }

        if (!allDigits) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        int pos = std::stoi(input);

        if (nodesByPosition.find(pos) == nodesByPosition.end()) {
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        TreeNode* node = nodesByPosition[pos];

        // node content
        std::cout << "Node's content: " << node->content << "\n";

        // one ancestor (direct parent) 
        if (node->parent)
            std::cout << "Ancestor: " << node->parent->content << "\n";
        else
            std::cout << "Ancestor: None (root node)\n";

        // one descendant (first child)
        if (!node->children.empty())
            std::cout << "Descendant: " << node->children[0]->content << "\n";
        else
            std::cout << "Descendant: None (leaf node)\n";

        // one sibling (first other child of the same parent) 
        std::string sibling = "None";
        if (node->parent)
            for (TreeNode* s : node->parent->children)
                if (s != node) { sibling = s->content; break; }

        std::cout << "Sibling: " << sibling << "\n";
    }
}
