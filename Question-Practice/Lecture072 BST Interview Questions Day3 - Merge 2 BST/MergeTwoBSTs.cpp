#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/h_920474
class TreeNode {
   public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : data(x), left(left), right(right) {}
};

void inorderVector(TreeNode* root, vector<int>& sorted) {
    if (root == nullptr) return;
    inorderVector(root->left, sorted);
    sorted.push_back(root->data);
    inorderVector(root->right, sorted);
}

vector<int> mergeSOrtedVector(vector<int>& sorted1, vector<int>& sorted2) {
    int n1 = sorted1.size();
    int n2 = sorted2.size();
    vector<int> sorted;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2) {
        if (sorted1[i] < sorted2[j]) {
            sorted.push_back(sorted1[i++]);
        } else {
            sorted.push_back(sorted2[j++]);
        }
    }
    while (i < n1) {
        sorted.push_back(sorted1[i++]);
    }
    while (j < n2) {
        sorted.push_back(sorted2[j++]);
    }
    return sorted;
}

TreeNode* inorderToBST(vector<int>& sorted, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(sorted[mid]);
    root->left = inorderToBST(sorted, start, mid - 1);
    root->right = inorderToBST(sorted, mid + 1, end);
    return root;
}

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
    vector<int> sorted1;
    inorderVector(root1, sorted1);
    vector<int> sorted2;
    inorderVector(root2, sorted2);
    vector<int> sorted = mergeSOrtedVector(sorted1, sorted2);
    return inorderToBST(sorted, 0, sorted.size() - 1);
}

int main() {
    // Create the first Binary Search Tree
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);

    // Create the second Binary Search Tree
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(8);
    root2->right = new TreeNode(12);
    root2->left->left = new TreeNode(7);
    root2->left->right = new TreeNode(9);
    root2->right->left = new TreeNode(11);
    root2->right->right = new TreeNode(13);

    // Merge the two Binary Search Trees
    TreeNode* mergedRoot = mergeBST(root1, root2);

    // Print the merged Binary Search Tree in inorder traversal
    vector<int> sorted;
    inorderVector(mergedRoot, sorted);
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}