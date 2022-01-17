#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {

    this->root = nullptr;

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

NodeRedBlackTree RedBlackTree::insertHelp(Node root, char data) {

    boolean f = false;

    if(root == nullptr) {

        return(new NodeRedBlackTree(data));

    }

    else if(data < root.data) {

            root.left = insertHelp(root.left, data);

            root.left.parent = root;

            if(root != this->root) {

                if(root->isBlack == false && root->left->isBlack == false) {

                    f = true;

                }

            }

        }

        else {

            root.right = insertHelp(root.right,data);
            root.right.parent = root;
            if(root!=this.root)
            {
                if(root.colour=='R' && root.right.colour=='R')
                    f = true;
            }
        // at the same time of insertion, we are also assigning parent nodes
        // also we are checking for RED RED conflicts
        }

        // now lets rotate.
        if(this.ll) // for left rotate.
        {
            root = rotateLeft(root);
            root.colour = 'B';
            root.left.colour = 'R';
            this.ll = false;
        }
        else if(this.rr) // for right rotate
        {
            root = rotateRight(root);
            root.colour = 'B';
            root.right.colour = 'R';
            this.rr  = false;
        }
        else if(this.rl)  // for right and then left
        {
            root.right = rotateRight(root.right);
            root.right.parent = root;
            root = rotateLeft(root);
            root.colour = 'B';
            root.left.colour = 'R';

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
