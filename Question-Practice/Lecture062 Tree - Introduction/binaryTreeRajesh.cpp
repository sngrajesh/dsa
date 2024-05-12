#include <bits/stdc++.h>
using namespace std;

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//
//                            1
//                      _____/|______
//                     /            \      
//                   3              5
//                  / \            / \     
//                 /  \           /  \     
//               7    11        17  -1
//              / \  / \       / \         
//            -1 -1 -1 -1    -1 -1
//
// Inorder : 7 3 11 1 17 5
// Preorder : 1 3 7 11 5 17
// Postorder : 7 11 3 17 5 1

class Node {
   public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root) {
    cout << "Enter Data : ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) return NULL;

    cout << endl << "Left Part of " << data;
    root->left = buildTree(root->left);
    cout << endl << "Right Part of " << data;
    root->right = buildTree(root->right);

    return root;
}

Node *buildFromVector(vector<int> &arr) {
    if (arr.empty()) {
        return NULL;
    }

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node *temp = q.front();
        q.pop();

        if (i < arr.size()) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
            i++;
        }

        if (i < arr.size()) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
            i++;
        }
    }

    // Check if all nodes were assigned correctly
    if (i != arr.size()) {
        // Constructed tree is not formed correctly
        return new Node(-1);
    }

    return root;
}

Node *buildFromLevelOrder(Node *root) {
    queue<Node *> q;
    int data;
    cout << "Root Data : ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << "Left Data for " << temp->data << " : ";
        cin >> data;
        if (data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Right Data for " << temp->data << " : ";
        cin >> data;
        if (data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}

void printTree(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void levelOrderTraverse(Node *root) {
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

void inOrder(Node *root) {
    // LNR
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root) {
    // NLR
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    // LRN
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrderWithoutBackTrack(Node *root) {
    // LNR
    if (root == NULL) return;

    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preOrderWithoutBackTrack(Node *root) {
    // NLR
    if (root == NULL) return;

    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            cout << curr->data << " ";  // Print the value here
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}

void postOrderWithoutBackTrack(Node *root) {
    // LRN
    if (root == NULL) return;

    stack<Node *> st;
    Node *curr = root;
    Node *prev = NULL;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();

        if (curr->right == NULL || curr->right == prev) {
            cout << curr->data << " ";  // Print the value here
            st.pop();
            prev = curr;
            curr = NULL;
        } else {
            curr = curr->right;
        }
    }
}

int main(int argc, char const *argv[]) {
    // Build Normal
    //  Node *root = buildTree(NULL);
    //  cout << endl;

    // Two ways of printing
    //  printTree(root);
    //  levelOrderTraverse(root);

    // Level Order Build
    //  Node *root = buildFromLevelOrder(NULL);
    //  cout << endl;
    //  levelOrderTraverse(root);

    vector<int> v = {1, 3, 5, 7, 11, 17};
    Node *root = buildFromVector(v);
    cout << endl;
    levelOrderTraverse(root);
    // Three ways of traversing
    cout << endl << "Inorder " << endl;
    inOrder(root);
    cout << endl;
    inOrderWithoutBackTrack(root);
    cout << endl << "Preorder " << endl;
    preOrder(root);
    cout << endl;
    preOrderWithoutBackTrack(root);
    cout << endl << "Postorder" << endl;
    postOrder(root);
    cout << endl;
    postOrderWithoutBackTrack(root);
    cout << endl;

    return 0;
}
