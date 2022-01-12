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

NodeBTree *NodeBTree::searchID(std::string id) {

    int i = 0;

    while (i < this->nKeys && id != this->keys[i]) {

        i++;

    }

    if (this->keys[i] == id) {

        return this;

    }

    if (this->leaf == true) {

        return NULL;

    }

    // Go to the appropriate child
    return this->children[i]->searchID(id);

}

void NodeBTree::traverse() {

    int i;

    for (i = 0; i < nKeys; i++) {

        if (leaf == false) {

            children[i]->traverse();

        }

        std::cout << " " << &keys[i];

    }

    // Print the subtree rooted with last child
    if (leaf == false) {

        children[i]->traverse();

    }

}
