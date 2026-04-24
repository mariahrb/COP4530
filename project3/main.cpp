#include <iostream>
#include <string>
#include "LinkedTree.h"

// Entry point: prompts for an input file, builds the decision tree,
// writes about_tree.txt, then runs the interactive exploration console.
int main() {
    std::string filename;
    std::cout << "Enter the tree input file name: ";
    std::cin >> filename;

    LinkedTree tree;
    tree.loadFromFile(filename);
    tree.generateOutputFile("about_tree.txt");
    tree.interactiveExplore();

    return 0;
}
