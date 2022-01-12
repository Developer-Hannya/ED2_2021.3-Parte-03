#include "BTree.h"

BTree::BTree(int degree) {

    this->root == NULL;

    this->maxDegree = degree;

}

BTree::~BTree() {

    delete this;

}

void BTree::callTraverse() {

    if (root != NULL) {

            root->traverse();

    }

}

std::string BTree::searchID(std::string id) {



}
