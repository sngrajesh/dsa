// https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472

/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorderVector(TreeNode<int> *root, vector<int> &sorted) {
    if (root == nullptr) return;
    inorderVector(root->left, sorted);
    sorted.push_back(root->data);
    inorderVector(root->right, sorted);
}
TreeNode<int> *inorderToBST(vector<int> sorted, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode<int> *root = new TreeNode<int>(sorted[mid]);
    root->left = inorderToBST(sorted, start, mid - 1);
    root->right = inorderToBST(sorted, mid + 1, end);
    return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root) {
    vector<int> sorted;
    inorderVector(root, sorted);
    return inorderToBST(sorted, 0, sorted.size() - 1);
}
