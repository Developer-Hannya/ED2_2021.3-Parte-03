#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "NodeRedBlackTree.h"

#include <iostream>


class RedBlackTree {

    public:

        NodeRedBlackTree *root;

        RedBlackTree();

        NodeRedBlackTree *rotateLeft(NodeRedBlackTree *node);

        NodeRedBlackTree *rotateRight(NodeRedBlackTree *node);

};

#endif // REDBLACKTREE_H_INCLUDED
