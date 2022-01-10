#ifndef NODEBTREE_H_INCLUDED
#define NODEBTREE_H_INCLUDED

#include <vector>
#include <string>

class NodeBTree {

    private:

        std::vector<std::string> *keys;

        int maxDegree;

        NodeBTree **children;

        int n;

        bool leaf;

    public:

        std::string BTree:: searchID(std::string id);

        void traverse();
}

};

#endif // NODEBTREE_H_INCLUDED
