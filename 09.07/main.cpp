#include "BinaryTree.hpp"


int main() {
    tree::Tree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.print(); // Output: 2 3 4 5 6 7 8

}
