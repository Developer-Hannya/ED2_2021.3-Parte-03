#ifndef NODEREDBLACKTREE_H_INCLUDED
#define NODEREDBLACKTREE_H_INCLUDED

class NodeRedBlackTree {

    public:

        char id;

        NodeRedBlackTree *left;

        NodeRedBlackTree *right;

        bool isBlack;

        NodeRedBlackTree *parent;

        NodeRedBlackTree(char data);

};

#endif // NODEREDBLACKTREE_H_INCLUDED
