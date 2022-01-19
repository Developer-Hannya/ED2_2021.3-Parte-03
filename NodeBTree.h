#ifndef NODEBTREE_H_INCLUDED
#define NODEBTREE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NodeBTree {

    public:

        char *keys;

        int maxDegree;

        NodeBTree **children;

        int nKeys;

        bool leaf;

        NodeBTree(int degree, bool leafi);

        NodeBTree *searchID(char id);

        void traverse();

        void insertIdNonFull(char id);

        void splitChild(int i, NodeBTree *y);

};

#endif // NODEBTREE_H_INCLUDED
