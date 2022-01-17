#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {

    this->root = nullptr;

}


NodeRedBlackTree RedBlackTree::RedBlackTree(NodeRedBlackTree node) {

    NodeRedBlackTree x = node->right;

    NodeRedBlackTree y = x->left;

    x->left = node;

    node->right = y;

    node->parent = x;

    if(y != null) {

        y->parent = node;

    }

    return x;

}
