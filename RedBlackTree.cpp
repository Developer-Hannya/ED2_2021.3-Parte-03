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

        else if(this.rl == true) {

            node->right = rotateRight(node->right);

            node->right->parent = ndoe;

            node = rotateLeft(node);

            node->colour = true;

            node->left->colour = false;

            this.rl = false;
        }
        else if(this.lr)  // for left and then right.
        {
            root.left = rotateLeft(root.left);
            root.left.parent = root;
            root = rotateRight(root);
            root.colour = 'B';
            root.right.colour = 'R';
            this.lr = false;
        }
        // when rotation and recolouring is done flags are reset.
        // Now lets take care of RED RED conflict
        if(f)
        {
            if(root.parent.right == root)  // to check which child is the current node of its parent
            {
                if(root.parent.left==null || root.parent.left.colour=='B')  // case when parent's sibling is black
                {// perform certaing rotation and recolouring. This will be done while backtracking. Hence setting up respective flags.
                    if(root.left!=null && root.left.colour=='R')
                        this.rl = true;
                    else if(root.right!=null && root.right.colour=='R')
                        this.ll = true;
                }
                else // case when parent's sibling is red
                {
                    root.parent.left.colour = 'B';
                    root.colour = 'B';
                    if(root.parent!=this.root)
                        root.parent.colour = 'R';
                }
            }
            else
            {
                if(root.parent.right==null || root.parent.right.colour=='B')
                {
                    if(root.left!=null && root.left.colour=='R')
                        this.rr = true;
                    else if(root.right!=null && root.right.colour=='R')
                        this.lr = true;
                }
                else
                {
                    root.parent.right.colour = 'B';
                    root.colour = 'B';
                    if(root.parent!=this.root)
                        root.parent.colour = 'R';
                }
            }
            f = false;
        }
        return(root);
    }
