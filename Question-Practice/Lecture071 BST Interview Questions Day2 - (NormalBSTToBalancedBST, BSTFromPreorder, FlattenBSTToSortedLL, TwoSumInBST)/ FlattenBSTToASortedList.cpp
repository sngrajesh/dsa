// https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459
#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorderVector(TreeNode<int> *root, vector<int> &sorted) {
    if (root == nullptr) return;
    inorderVector(root->left, sorted);
    sorted.push_back(root->data);
    inorderVector(root->right, sorted);
}

TreeNode<int> *flatten(TreeNode<int> *root) {
    vector<int> sorted;
    inorderVector(root, sorted);

    TreeNode<int> *ansRoot = new TreeNode<int>(sorted[0]);
    TreeNode<int> *curr = ansRoot;
    int n = sorted.size();
    for (int i = 1; i < n; i++) {
        TreeNode<int> *temp = new TreeNode<int>(sorted[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return ansRoot;
}
 