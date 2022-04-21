#include "datastructures.hpp"
int main(){
    BinarySearchTree bst = BinarySearchTree();
    bst.insert(2);
    bst.insert(1);
    bst.insert(4);
    bst.insert(3);
    bst.insert(5);
    bst.erase(2);
    BTNode* root = bst.get_root();
    bst.inorder(root);
    
    return 0;
    }
