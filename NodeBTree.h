#ifndef NODEBTREE_H_INCLUDED
#define NODEBTREE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NodeBTree {

    private:

        std::vector<std::string> *keys;

        int maxDegree;

        NodeBTree **children;

        int nKeys;

        bool leaf;

    public:

        NodeBTree(int degree, bool leafi);

        NodeBTree *searchID(std::string id);

        void traverse();

        void insertId(std::string id);

        void splitChild(int i, NodeBTree *y);

};

#endif // NODEBTREE_H_INCLUDED
