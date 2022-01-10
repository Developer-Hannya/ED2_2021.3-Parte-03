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

        std::string searchID(std::string id);

        void callTraverse();

};

#endif // BTREE_H_INCLUDED
