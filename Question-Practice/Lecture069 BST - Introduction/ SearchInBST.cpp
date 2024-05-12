// https://www.naukri.com/code360/problems/search-in-bst_1402878
/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) :
   data(x), left(left), right(right) {}
    };

*/

/*
    Time Complexity : O(H)
    Space Complexity : O(H)

    Where 'H' is the height of the given BST.
*/

bool searchInBSTOHSpace(BinaryTreeNode<int> *root, int x) {
    if (root == NULL) return false;
    if (root->data == x) return true;

    if (root->data < x)
        searchInBST(root->right, x);
    else
        searchInBST(root->left, x);
}

/*
    Time Complexity : O(H)
    Space Complexity : O(1)

    Where 'H' is the height of the given BST.
*/

bool searchInBSTO1Space(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *ptr = root;

    while (ptr != NULL) {
        if (ptr->data == x) {
            return true;
        } else if (ptr->data > x) {
            // Move 'ptr' to left child.
            ptr = ptr->left;
        } else {
            // Move 'ptr' to left child.
            ptr = ptr->right;
        }
    }

    return false;
}