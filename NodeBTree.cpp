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

void NodeBTree::insertIdNonFull(char id) {

    int i = nKeys-1;

    if (leaf == true) {

        while (i >= 0 && keys[i] > id) {

            keys[i+1] = keys[i];

            i--;

        }

        keys[i+1] = id;

        nKeys++;

    }

    else {

        while (i >= 0 && keys[i] > id)
            i--;

        if (children[i+1]->nKeys == 2 * maxDegree - 1) {

            splitChild(i+1, children[i+1]);

            if (keys[i+1] < id) {

                i++;

            }

        }

        children[i+1]->insertIdNonFull(id);

    }

}

void NodeBTree::splitChild(int i, NodeBTree *y) {

    NodeBTree *z = new NodeBTree(y->maxDegree, y->leaf);

    z->nKeys = maxDegree - 1;

    for (int j = 0; j < maxDegree - 1; j++) {

        z->keys[j] = y->keys[j + maxDegree];

    }


    if (y->leaf == false) {

        for (int j = 0; j < maxDegree; j++) {

            z->children[j] = y->children[j + maxDegree];

        }

    }

    y->nKeys = maxDegree - 1;

    for (int j = nKeys; j >= i + 1; j--) {

        children[j + 1] = children[j];

    }

    children[i + 1] = z;

    for (int j = nKeys - 1; j >= i; j--) {

        keys[j + 1] = keys[j];

    }

    keys[i] = y->keys[maxDegree - 1];

    nKeys++;

}
