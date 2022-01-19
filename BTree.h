#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <string>

#include "NodeBTree.h"

class BTree {


    public:

        NodeBTree *root;

        int maxDegree;

        BTree(int degree);

        ~BTree();

        NodeBTree* callSearch(char id);

        void callTraverse();

        void insertId(int n, char id);

        NodeBTree setRoot(char id);

};

#endif // BTREE_H_INCLUDED
