// https://www.geeksforgeeks.org/problems/construct-tree-1/1
//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findposition(int element , int in[] , int start , int end){
        for(int i = start ; i <= end ; i++)
            if(in[i] == element)
                return i;
        return -1;
    }
    
    Node *solve(int in[],int pre[], int &preOrderStartIndex ,int inOrderStart, 
    int inOrderEnd ,int size){
        
        if(preOrderStartIndex >= size || inOrderStart > inOrderEnd) return NULL; 
     
        int element  = pre[preOrderStartIndex++];
        int positionn = findposition(element , in , inOrderStart, inOrderEnd);
        
        Node* root = new Node(element);
        
        root->left = solve(in, pre, preOrderStartIndex ,inOrderStart , positionn - 1 , size );
        root->right = solve(in, pre, preOrderStartIndex ,positionn + 1 , inOrderEnd , size );
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        
        
        int preOrderStartIndex  = 0;
        Node* root =solve(in, pre, preOrderStartIndex ,0 , n-1 , n) ;

        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends




/*
* Iteration 1:
*  
* Input:
* inorder[] = {3 1 4 0 5 2}
* preorder[] = {0 1 3 4 2 5}
* 
* int inOrderStart = 0
* int inOrderEnd = 5
* int preOrderStartIndex = 0
* 
* Build the root node with data 0
*          0
* 
* 
* 
* Iteration 2:
* Input:
* inorder[] = {3 1 4 0 5 2}
* preorder[] = {0 1 3 4 2 5}
* 
* int inOrderStart = 0
* int inOrderEnd = 5
* int preOrderStartIndex = 1
* 
* Find 0 in inorder array, divide it into left and right subtrees
*          0
*         / \
*        /   \
* left:  {3 1 4}
* right: {5 2}
* 
* 
* Iteration 3:
* Input:
* inorder[] = {3 1 4}
* preorder[] = {1 3 4}
* 
* int inOrderStart = 0
* int inOrderEnd = 2
* int preOrderStartIndex = 2
* 
* Build the root node with data 1
*          0
*         / \
*        /   \
*       1     {5 2}
*      / \
* left: {3} right: {4}
* 
* 
* Iteration 4:
* Input:
* inorder[] = {3}
* preorder[] = {3}
* 
* int inOrderStart = 0
* int inOrderEnd = 0
* int preOrderStartIndex = 3
* 
* Build the root node with data 3
*          0
*         / \
*        /   \
*       1     {5 2}
*      / \
*     3   {4}
* 
* 
* Iteration 5:
* Input:
* inorder[] = {4}
* preorder[] = {4}
* 
* int inOrderStart = 0
* int inOrderEnd = 0
* int preOrderStartIndex = 4
* 
* Build the root node with data 4
*          0
*         / \
*        /   \
*       1     {5 2}
*      / \
*     3   4
* 
* 
* Iteration 6:
* Input:
* inorder[] = {5 2}
* preorder[] = {2 5}
* 
* int inOrderStart = 0
* int inOrderEnd = 1
* int preOrderStartIndex = 5
* 
* Build the root node with data 2
*          0
*         / \
*        /   \
*       1     2
*      / \   /
*     3   4 5
* 
*/