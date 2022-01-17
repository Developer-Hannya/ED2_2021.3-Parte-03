#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "NodeRedBlackTree.h"

#include <iostream>


class RedBlackTree {

    NodeRedBlackTree *root;

    RedBlackTree();

    NodeRedBlackTree rotateLeft(NodeRedBlackTree node);

};

#endif // REDBLACKTREE_H_INCLUDED
