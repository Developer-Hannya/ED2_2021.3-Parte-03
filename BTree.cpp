#include "BTree.h"

BTree::BTree(int degree) {

    root == NULL;

    maxDegree = degree;

}

BTree::~BTree() {

    delete this;

}

void BTree::callTraverse() {

    if (root != NULL) {

            root->traverse();

    }

}

NodeBTree *BTree::callSearch(char id) {

    return (root == NULL)? NULL : root->searchID(id);

}

void BTree::insertId(char id) {

    if (root == NULL) {

        root = new NodeBTree(6, true);

        root->setKeys(id);

        root->setNKeys(1);

    }

    else {

        if (root->getNKeys() == 2*maxDegree-1) {

            NodeBTree *s = new NodeBTree(maxDegree, false);

            s->children[0] = root;

            s->splitChild(0, root);

            int i = 0;

            if (s->keys[0] < id) {

                i++;

            }

            s->children[i]->insertId(id);

            root = s;
        }

        else {

            root->insertId(id);

        }

    }

}
