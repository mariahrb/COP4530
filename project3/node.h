#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

// Represents a single node in the linked general decision tree
struct TreeNode {
    std::string content;             // The text/question displayed at this node
    std::string edgeLabel;           // Label on the incoming edge (e.g., "Yes", "No")
    int level;                       // Depth in the tree (root = level 0)
    int preorderPos;                 // Position in preorder traversal (1-based)
    TreeNode* parent;                // Pointer to parent node (nullptr for root)
    std::vector<TreeNode*> children; // Ordered list of child nodes

    // Constructs a node with the given content, edge label, level, and preorder position
    TreeNode(const std::string& c, const std::string& e, int lev, int pos)
        : content(c), edgeLabel(e), level(lev), preorderPos(pos), parent(nullptr) {}
};

#endif // NODE_H
