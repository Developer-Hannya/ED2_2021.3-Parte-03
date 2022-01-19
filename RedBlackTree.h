#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "NodeRedBlackTree.h"

#include <iostream>


class RedBlackTree {

    public:

        NodeRedBlackTree *root;

        bool ll;

        bool rr;

        bool lr;

        bool rl;

        RedBlackTree();

        NodeRedBlackTree *rotateLeft(NodeRedBlackTree *node);

        NodeRedBlackTree *rotateRight(NodeRedBlackTree *node);

        NodeRedBlackTree *insertHelp(NodeRedBlackTree *root, char data);

        void insertId(char data);

        NodeRedBlackTree *searchId(NodeRedBlackTree *node, char id);

};

#endif // REDBLACKTREE_H_INCLUDED
