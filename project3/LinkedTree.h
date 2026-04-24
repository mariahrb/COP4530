#ifndef LINKEDTREE_H
#define LINKEDTREE_H

#include "node.h"
#include <string>
#include <vector>
#include <map>
#include <ostream>

class LinkedTree {
private:
    TreeNode* root;                           // pointer to the root of the tree
    std::map<int, TreeNode*> nodesByPosition; // maps preorder position to its node

    // recursively prints dash-indented visualization (level * 2 dashes) to out
    void printVisualization(TreeNode* node, std::ostream& out);

    // collects all internal (non-leaf) nodes into result in preorder
    void collectInternalNodes(TreeNode* node, std::vector<TreeNode*>& result);

    // collects all external (leaf) nodes into result in preorder
    void collectExternalNodes(TreeNode* node, std::vector<TreeNode*>& result);

    // returns the height of the subtree rooted at node (edges on longest root-to-leaf path)
    int computeHeight(TreeNode* node);

    // returns true if every node in the subtree has at most 2 children
    bool checkBinaryTree(TreeNode* node);

    // returns true if every internal node has exactly 2 children (proper binary tree)
    bool checkProperBinaryTree(TreeNode* node);

    // returns true if all leaves are at treeHeight level (perfect binary tree)
    bool checkPerfectBinaryTree(TreeNode* node, int treeHeight, int currentLevel);

    // returns the subtree height if the subtree is height-balanced, or -1 if not
    int computeBalancedHeight(TreeNode* node);

    // recursively frees all dynamically allocated nodes
    void destroyTree(TreeNode* node);

public:
    // constructs an empty tree
    LinkedTree();

    // destructor: releases all allocated memory
    ~LinkedTree();

    // parses the given input file and builds the linked tree structure
    void loadFromFile(const std::string& filename);

    // writes tree visualization, properties, and binary analysis to outputFilename
    void generateOutputFile(const std::string& outputFilename);

    // runs an interactive console session for exploring nodes by preorder position
    void interactiveExplore();
};

#endif // LINKEDTREE_H
