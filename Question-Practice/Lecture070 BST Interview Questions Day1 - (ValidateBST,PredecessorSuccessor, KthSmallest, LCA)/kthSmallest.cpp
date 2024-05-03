// https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333
#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int kthSmallestUtil(BinaryTreeNode<int>* root, int k, int& n) {
    if (root == NULL) return -1;
    int left = kthSmallestUtil(root->left, k, n);
    if (left != -1) return left;
    n = n + 1;
    if (n == k) return root->data;
    int right = kthSmallestUtil(root->right, k, n);
    return right;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int n = 0;
    int ans = kthSmallestUtil(root, k, n);
    return ans;
}

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is number of nodes in binary serach tree.
*/

void inorder2(BinaryTreeNode<int>* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }

    //  Recur for the left subtree.
    inorder2(root->left, arr);

    arr.push_back(root->data);

    //  Recur for the right subtree.
    inorder2(root->right, arr);
}

int kthSmallest2(BinaryTreeNode<int>* root, int k) {
    // To store the inorder traversal of the tree.
    vector<int> arr;

    inorder2(root, arr);

    if (k > arr.size()) {
        return -1;
    } else {
        return arr[k - 1];
    }
}

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is number of nodes in binary serach tree.
*/

int kthSmallest3(BinaryTreeNode<int>* root, int k) {
    stack<BinaryTreeNode<int>*> stack;  // To store the node

    while (true) {
        // Add all the left child of root, in stack
        while (root) {
            stack.push(root);
            root = root->left;
        }

        // If stack is empty then return -1
        if (stack.size() == 0) {
            return -1;
        }
        root = stack.top();
        stack.pop();
        k -= 1;
        if (!k) {
            return root->data;
        }
        root = root->right;
    }
}

/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is number of nodes in binary serach tree->
*/

int morrisTraversal(BinaryTreeNode<int>* root, int k) {
    BinaryTreeNode<int>* curNode = root;

    while (curNode != NULL) {
        if (curNode->left == NULL) {
            k = k - 1;

            //* If 'curNode' is 'k-th' smallest node
            if (k == 0) {
                return curNode->data;
            }
            curNode = curNode->right;
        } else {
            BinaryTreeNode<int>* prev = curNode->left;

            //* Find rightmost child node of 'curNode'
            while (prev->right != NULL && prev->right != curNode) {
                prev = prev->right;
            }

            //* If rightmost node is leaf node Make a connection between
            //* rightmost node and 'curNode'
            if (prev->right == NULL) {
                prev->right = curNode;
                curNode = curNode->left;
            }

            else {
                prev->right = NULL;
                k = k - 1;
                if (k == 0) {
                    // If 'curNode' is 'k-th' smallest node
                    return (curNode->data);
                }
                curNode = curNode->right;
            }
        }
    }

    // If number of nodes less than 'k'
    return -1;
}

int kthSmallest4(BinaryTreeNode<int>* root, int k) {
    // Find 'k-th' smallest node with help of morris traversal
    return morrisTraversal(root, k);
}