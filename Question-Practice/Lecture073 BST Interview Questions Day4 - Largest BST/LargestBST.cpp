// https://www.naukri.com/code360/problems/largest-bst-subtree_893103
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
   right(right) {}
    };
*/

pair<pair<int, int>, pair<bool, int>> largestBSTFast(TreeNode *root,
                                                     int &maxSize) {
  if (root == NULL)
    return make_pair(make_pair(INT_MAX, INT_MIN), make_pair(true, 0));

  pair<pair<int, int>, pair<bool, int>> left =
      largestBSTFast(root->left, maxSize);
  pair<pair<int, int>, pair<bool, int>> right =
      largestBSTFast(root->right, maxSize);

  int mini = min(root->data, left.first.first);
  int maxi = max(root->data, right.first.second);
  bool isBST = left.second.first && right.second.first &&
               (root->data > left.first.second) &&
               (root->data < right.first.first);
  int size = 1 + left.second.second + right.second.second;

  if (isBST) {
    maxSize = max(maxSize, size);
  }

  return make_pair(make_pair(mini, maxi), make_pair(isBST, size));
}

int largestBST(TreeNode *root) {
  int maxSize = 0;
  //              min  max         valid  size
  pair<pair<int, int>, pair<bool, int>> ans = largestBSTFast(root, maxSize);

  return maxSize;
}