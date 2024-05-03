// C++ Code for the above approach

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has the following
attributes: val, left node child pointer,
and right node child pointer.*/
class Node {
   public:
    int val;
    Node* left;
    Node* right;
};

// a method that produces a new Node
Node* newNode(int val) {
    Node* nodes = new Node();
    nodes->val = val;
    nodes->left = NULL;
    nodes->right = NULL;

    return (nodes);
}

// Function to create a doubly
// linked list from bst
void bstreeTodllist(Node* root, Node*& hd) {
    // if root is NULL
    if (!root) return;

    // Recursively convert the right node subtree
    bstreeTodllist(root->right, hd);

    // Update root
    root->right = hd;

    // if hd is not NULL
    if (hd) {
        // Update left of the hd
        hd->left = root;
    }

    // Update hd
    hd = root;

    // Recursively convert the left node subtree
    bstreeTodllist(root->left, hd);
}

// combining two sorted linked lists function
Node* mergedLinkedList(Node* hd1, Node* hd2) {
    // Create the result list's hd and tl
    Node* hd = NULL;
    Node* tl = NULL;

    while (hd1 && hd2) {
        if (hd1->val < hd2->val) {
            if (!hd)
                hd = hd1;
            else {
                tl->right = hd1;
                hd1->left = tl;
            }

            tl = hd1;
            hd1 = hd1->right;
        }

        else {
            if (!hd)
                hd = hd2;
            else {
                tl->right = hd2;
                hd2->left = tl;
            }

            tl = hd2;
            hd2 = hd2->right;
        }
    }

    while (hd1) {
        tl->right = hd1;
        hd1->left = tl;
        tl = hd1;
        hd1 = hd1->right;
    }

    while (hd2) {
        tl->right = hd2;
        hd2->left = tl;
        tl = hd2;
        hd2 = hd2->right;
    }

    // Return the created DLL
    return hd;
}

// list to bst conversion function
Node* sortedListToBST(Node*& hd, int y) {
    // if hd is null or left node is not an element
    if (y <= 0 || !hd) return NULL;

    // Recursively create the left node component from the list
    Node* left = sortedListToBST(hd, y / 2);

    Node* root = hd;
    root->left = left;
    hd = hd->right;

    // Create the left node paroot recursively from the list
    root->right = sortedListToBST(hd, y - (y / 2) - 1);

    // Return the root of BST
    return root;
}

// Two balanced BSTs are combined by this function
Node* mergeTrees(Node* root1, Node* root2, int x, int y) {
    // Create sorted Doubly Linked Lists from BSTs

    Node* hd1 = NULL;
    bstreeTodllist(root1, hd1);
    hd1->left = NULL;

    Node* hd2 = NULL;
    bstreeTodllist(root2, hd2);
    hd2->left = NULL;

    // Combine the two sorted lists into a single one
    Node* hd = mergedLinkedList(hd1, hd2);

    // Make a tree out of the combined lists
    return sortedListToBST(hd, x + y);
}

void printInorder(Node* nodes) {
    // if current node is NULL
    if (!nodes) {
        return;
    }

    printInorder(nodes->left);

    // current value's nodes in print
    cout << nodes->val << " ";

    printInorder(nodes->right);
}

/* Driver code*/
int main() {
    /* Create following tree as first balanced BST
        110
        / \
      60 400
     / \
    10 90
    */

    Node* root1 = newNode(110);
    root1->left = newNode(60);
    root1->right = newNode(400);
    root1->left->left = newNode(10);
    root1->left->right = newNode(90);
    /* Create following tree as second balanced BST
            100
            / \
          30 130
    */
    Node* root2 = newNode(100);
    root2->left = newNode(30);
    root2->right = newNode(130);

    // Function Call
    Node* mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "The merged data is traversed "
            "tree in order as shown below \n";
    printInorder(mergedTree);

    return 0;
}