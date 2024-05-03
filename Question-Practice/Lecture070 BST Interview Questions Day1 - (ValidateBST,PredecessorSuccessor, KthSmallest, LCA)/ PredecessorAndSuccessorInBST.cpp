// https://www.naukri.com/code360/problems/_893049
/*************************************************************

    Following is the Binary Tree node structure
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

*************************************************************/
/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the number of nodes in the BST.
*/

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    int pred = -1, succ = -1;
    TreeNode *current = root;
    while (current != NULL) {
        if (current->data == key) {
            // Predecessor
            if (current->left != NULL) {
                TreeNode *temp = current->left;
                while (temp->right != NULL) temp = temp->right;
                pred = temp->data;
            }
            // Successor
            if (current->right != NULL) {
                TreeNode *temp = current->right;
                while (temp->left != NULL) temp = temp->left;
                succ = temp->data;
            }
            break;
        } else if (current->data > key) {
            succ = current->data;
            current = current->left;
        } else {
            pred = current->data;
            current = current->right;
        }
    }
    return make_pair(pred, succ);
}
 
/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    where 'N' is the number of nodes in the BST.
*/

// Finding inorder.
void inorder(TreeNode *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // To store the inorder traversal of the BST.
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int predecessor = -1, successor = -1;

    // Finding predecessor.
    for (int i = 0; i < inorderArray.size(); i++)
    {
        if (inorderArray[i] < key)
        {
            predecessor = inorderArray[i];
        }
    }

    // Finding successor.
    for (int i = inorderArray.size() - 1; i >= 0; i--)
    {
        if (inorderArray[i] > key)
        {
            successor = inorderArray[i];
        }
    }

    // We are returning here.
    return {predecessor, successor};
}