#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

// represents a single node in the linked general decision tree
struct TreeNode {
    std::string content;             // the text/question displayed at this node
    std::string edgeLabel;           // label on the incoming edge (e.g., "Yes", "No")
    int level;                       // depth in the tree (root = level 0)
    int preorderPos;                 // position in preorder traversal (1-based)
    TreeNode* parent;                // pointer to parent node (nullptr for root)
    std::vector<TreeNode*> children; // ordered list of child nodes

    // constructs a node with the given content, edge label, level, and preorder position
    TreeNode(const std::string& c, const std::string& e, int lev, int pos)
        : content(c), edgeLabel(e), level(lev), preorderPos(pos), parent(nullptr) {}
};

#endif // NODE_H
