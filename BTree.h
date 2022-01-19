#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <string>

#include "NodeBTree.h"

class BTree {

    private:

        NodeBTree *root;

        int maxDegree;

    public:

        BTree(int degree);

        ~BTree();

        NodeBTree* callSearch(char id);

        void callTraverse();

        void insertId(char id);

        NodeBTree setRoot(char id);

};

#endif // BTREE_H_INCLUDED
