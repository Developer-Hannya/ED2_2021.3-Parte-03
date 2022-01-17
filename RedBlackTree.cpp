#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {

    this->root = nullptr;

}


NodeRedBlackTree *RedBlackTree::rotateLeft(NodeRedBlackTree *node) {

    NodeRedBlackTree *x = node->right;

    NodeRedBlackTree *y = x->left;

    x->left = node;

    node->right = y;

    node->parent = x;

    if(y != nullptr) {

        y->parent = node;

    }

    return x;

}

NodeRedBlackTree *RedBlackTree::rotateRight(NodeRedBlackTree *node) {

    NodeRedBlackTree *x = node->left;

    NodeRedBlackTree *y = x->right;

    x->right = node;

    node->left = y;

    node->parent = x;

    if(y != nullptr) {

        y->parent = node;

    }

    return x;

}
