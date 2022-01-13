#include "NodeBTree.h"

#include <iostream>

using namespace std;


NodeBTree::NodeBTree(int degree, bool leafi) {

    setMaxDegree(degree);

    leaf = leafi;

    //this->keys->size() = 2 * maxDegree - 1;

    this->children = new NodeBTree *[2 * maxDegree];

    this->setNKeys(0);

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


void NodeBTree::setKeys(char key, int i) {

    if (keys[i] == NULL) {

        keys[i] = key;

    }

}

void NodeBTree::setMaxDegree(int x) {

    this->maxDegree = x;

}

void NodeBTree::setNKeys(int n) {

    this->nKeys = n;

}

void NodeBTree::setBoolLeaf(bool l) {

    this->leaf = l;

}

char NodeBTree::getKeys(int index) {

    for (int i = 0; i < this->nKeys; i++) {

        return keys[i];

    }

}

int NodeBTree::getMaxDegree() {

    return this->maxDegree;

}

int NodeBTree::getNKeys() {

    return this->nKeys;

}

bool NodeBTree::getLeaf() {

    return this->leaf;

}
