#ifndef NODEBTREE_H_INCLUDED
#define NODEBTREE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NodeBTree {

    private:

        char *keys;

        int maxDegree;

        NodeBTree **children;

        int nKeys;

        bool leaf;

    public:

        NodeBTree(int degree, bool leafi);

        NodeBTree *searchID(char id);

        void traverse();

        void insertId(char id);

        void splitChild(int i, NodeBTree *y);

        ///gets e sets

        void setKeys(char key);

        void setMaxDegree(int x);

        void setNKeys(int n);

        void setBoolLeaf(bool l);

        char getKeys(int index);

        int getMaxDegree();

        int getNKeys();

        bool getLeaf();

};

#endif // NODEBTREE_H_INCLUDED
