#include <bits/stdc++.h>

/*
   Time Complexity : O(N^2)
   Space Complexity : O(N)

   Where N denotes number of nodes in the array/list.
*/

BinaryTreeNode<int> *insertNodeBST2(BinaryTreeNode<int> *root, int data) {
    if (root == NULL) {
        root = new BinaryTreeNode<int>(data);
        return root;
    }

    if (root->data > data) {
        root->left = insertNodeBST(root->left, data);
    } else {
        root->right = insertNodeBST(root->right, data);
    }
    return root;
}

BinaryTreeNode<int> *preorderToBST2(vector<int> &preorder) {
    BinaryTreeNode<int> *root = NULL;

    for (auto i : preorder) {
        root = insertNodeBST(root, i);
    }
    return root;
}

/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where N denotes number of nodes in the array/list.
*/

BinaryTreeNode<int> *preorderToBSTUtil(vector<int> &preorder, int min, int max,
                                       int &i) {
    if (i >= preorder.size()) return NULL;
    if (preorder[i] < min || preorder[i] > max) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[i++]);

    root->left = preorderToBSTUtil(preorder, min, root->data, i);
    root->right = preorderToBSTUtil(preorder, root->data, max, i);
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int index = 0;
    return preorderToBSTUtil(preorder, min, max, index);
}