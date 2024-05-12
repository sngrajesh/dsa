// https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631

#include <bits/stdc++.h>
// Following is the Binary Tree node structure
/**************
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

};
***************/
void inorderVector(BinaryTreeNode<int> *root, vector<int> &sorted) {
  if (root == nullptr)
    return;
  inorderVector(root->left, sorted);
  sorted.push_back(root->data);
  inorderVector(root->right, sorted);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target) {
  vector<int> sorted;
  inorderVector(root, sorted);

  int i = 0;
  int j = sorted.size() - 1;
  while (i < j) {
    if (sorted[i] + sorted[j] == target)
      return true;
    else if (sorted[i] + sorted[j] < target)
      i++;
    else
      j--;
  }
  return false;
}