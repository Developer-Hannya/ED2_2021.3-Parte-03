#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {

    this->root = nullptr;

    ll = false;

    rr = false;

    lr = false;

    rl = false;

}


NodeRedBlackTree *RedBlackTree::rotateLeft(NodeRedBlackTree *node) {

    NodeRedBlackTree *x = node->right;

    NodeRedBlackTree *y = x->left;

    x->left = node;

    node->right = y;

    node->parent = x;

    if(y != nullptr) {

        y->parent = node;

    }

    return x;

}

NodeRedBlackTree *RedBlackTree::rotateRight(NodeRedBlackTree *node) {

    NodeRedBlackTree *x = node->left;

    NodeRedBlackTree *y = x->right;

    x->right = node;

    node->left = y;

    node->parent = x;

    if(y != nullptr) {

        y->parent = node;

    }

    return x;

}

NodeRedBlackTree *RedBlackTree::insertHelp(NodeRedBlackTree *node, char data) {

    bool f = false;

    if(node == nullptr) {

        return(new NodeRedBlackTree(data));

    }

    else if(data < node->id) {

            node->left = insertHelp(node->left, data);

            node->left->parent = root;

            if(node != this->root) {

                if(node->isBlack == false && node->left->isBlack == false) {

                    f = true;

                }

            }

        }

        else {

            node->right = insertHelp(node->right, data);
            node->right->parent = node;
            if(node != this->root) {

                if(node->isBlack == false && node->right->isBlack == false) {

                    f = true;

                }

            }

        }

        if(this->ll == true) {

            node = rotateLeft(node);

            node->isBlack = true;

            node->left->isBlack = false;

            this->ll = false;

        }

        else if(this->rr == true) {

            node = rotateRight(node);

            node->isBlack = true;

            node->right->isBlack = false;

            this->rr  = false;

        }

        else if(this->rl == true) {

            node->right = rotateRight(node->right);

            node->right->parent = node;

            node = rotateLeft(node);

            node->isBlack = true;

            node->left->isBlack = false;

            this->rl = false;
        }

        else if(this->lr) {

            node->left = rotateLeft(node->left);

            node->left->parent = node;

            node = rotateRight(node);

            node->isBlack = true;

            node->right->isBlack = false;

            this->lr = false;

        }

        if(f == true) {

            if(node->parent->right == node) {

                if(node->parent->left == nullptr || node->parent->left->isBlack == true) {

                    if(node->left != nullptr && node->left->isBlack == false) {

                        this->rl = true;

                    }

                    else if(node->right != nullptr && node->right->isBlack == false) {

                        this->ll = true;

                    }
                }

                else {

                    node->parent->left->isBlack = true;

                    node->isBlack = true;

                    if(node->parent != this->root) {

                        node->parent->isBlack = false;

                    }

                }

            }

            else {

                if(node->parent->right == nullptr || node->parent->right->isBlack == true) {

                    if(node->left != nullptr && node->left->isBlack == false) {

                        this->rr = true;

                    }

                    else if(node->right != nullptr && node->right->isBlack == false) {

                        this->lr = true;

                    }

                }

                else {

                    node->parent->right->isBlack = true;

                    node->isBlack = true;

                    if(node->parent != this->root) {

                        node->parent->isBlack = false;

                    }

                }
            }

            f = false;

        }

    return(node);

}

void RedBlackTree::insertId(char data) {

        if(this->root == nullptr) {

            this->root = new NodeRedBlackTree(data);

            this->root->isBlack = true;

        }

        else {

            this->root = insertHelp(this->root, data);

        }

    }
