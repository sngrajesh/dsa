#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty()) {
                // queue still has some child ndoes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchInBST(Node* root, int x) {
    Node* ptr = root;

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

Node* getMinBST(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

Node* getMaxBST(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}

// Function to find the inorder predecessor of a given node
Node* inorderPredecessor(Node* root, Node* node) {
    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (root->data >= node->data) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

// Function to find the inorder successor of a given node
Node* inorderSuccessor(Node* root, Node* node) {
    Node* successor = nullptr;
    while (root != nullptr) {
        if (root->data <= node->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

Node* deleteNodeBST(Node* root, int data) {
    if (root == NULL) return root;

    if (root->data == data) {
        //*! O Child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //*! 1 Child
        //*? 1 Child - Left
        else if (root->left != NULL && root->right == NULL) {
            Node* left = root->left;
            delete root;
            return left;
        }
        //*? 1 Child - Right
        else if (root->left == NULL && root->right != NULL) {
            Node* right = root->right;
            delete root;
            return right;
        }
        //*! 2 Child
        else if (root->left != NULL && root->right != NULL) {
            int miniMumValue = (getMinBST(root->right))->data;
            root->data = miniMumValue;
            root->right = deleteNodeBST(root->right, miniMumValue);
            return root;
        }
    } else if (root->data > data) {
        root->left = deleteNodeBST(root->left, data);
        return root;
    } else {
        root->right = deleteNodeBST(root->right, data);
        return root;
    }
    return root;
}

Node* insertNodeBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (root->data > data) {
        root->left = insertNodeBST(root->left, data);
    } else {
        root->right = insertNodeBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int n;
    cout << "Enter Data : ";
    cin >> n;
    while (n != -1) {
        root = insertNodeBST(root, n);
        cin >> n;
    }
}

int main(int argc, char const* argv[]) {
    Node* root = NULL;
    takeInput(root);
    cout << endl << "In Order" << endl;
    inorder(root);
    cout << endl << "Pre Order" << endl;
    preorder(root);
    cout << endl << "Post Order" << endl;
    postorder(root);
    cout << endl << "Level Order" << endl;
    levelOrderTraversal(root);
    cout << endl << "Min : " << (getMinBST(root))->data << endl;
    cout << endl << "Max : " << (getMaxBST(root))->data << endl;

    // Find inorder predecessor and successor
    Node* node = root;
    Node* predecessor = inorderPredecessor(root, node);
    Node* successor = inorderSuccessor(root, node);

    cout << "Node Element: " << node->data << endl;
    cout << "Inorder Predecessor: "
         << (predecessor ? to_string(predecessor->data) : "None") << endl;
    cout << "Inorder Successor: "
         << (successor ? to_string(successor->data) : "None") << endl;

    deleteNodeBST(root, 14);
    cout << endl << "Level Order" << endl;
    levelOrderTraversal(root);

    return 0;
}