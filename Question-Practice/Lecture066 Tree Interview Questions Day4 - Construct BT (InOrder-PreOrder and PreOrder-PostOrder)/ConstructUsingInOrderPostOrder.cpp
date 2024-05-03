// https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1


//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure
    
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    int findposition(int element , int in[] , int start , int end){
        for(int i = start ; i <= end ; i++)
            if(in[i] == element)
                return i;
        return -1;
    }
    
    Node *solve(int in[],int post[], int &postOrderStartIndex ,int inOrderStart, 
    int inOrderEnd ,int size){
        
        if(postOrderStartIndex < 0 || inOrderStart > inOrderEnd) return NULL; 
     
        int element  = post[postOrderStartIndex--];
        int positionn = findposition(element , in , inOrderStart, inOrderEnd);
        
        Node* root = new Node(element);
        
        root->right = solve(in, post, postOrderStartIndex ,positionn + 1 , inOrderEnd , size );
        root->left = solve(in, post, postOrderStartIndex ,inOrderStart , positionn - 1 , size );
        
        return root;
    }
    
    Node *buildTree(int in[], int post[], int n) {
        int postOrderStartIndex  = n-1;
        Node* root =solve(in, post, postOrderStartIndex ,0 , n-1 , n) ;

        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends