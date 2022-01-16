#include "NodeBTree.h"

#include <iostream>

using namespace std;


NodeBTree::NodeBTree(int degree, bool leafi) {

    maxDegree = degree;

    leaf = leafi;

    //this->keys->size() = 2 * maxDegree - 1;

    this->children = new NodeBTree *[2 * maxDegree];

    this->nKeys = 0;

}

NodeBTree *NodeBTree::searchID(char id) {

    int i = 0;

    while (i < nKeys && id != keys[i]) {

        i++;

    }

    if (keys[i] == id) {

        return this;

    }

    if (leaf == true) {

        return NULL;

    }

    return children[i]->searchID(id);

}

void NodeBTree::traverse() {

    int i;

    for (i = 0; i < nKeys; i++) {

        if (leaf == false) {

            children[i]->traverse();

        }

        std::cout << " " << &keys[i];

    }

    if (leaf == false) {

        children[i]->traverse();

    }

}
