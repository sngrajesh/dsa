//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}


void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private: 
    struct Node* reverseLL(struct Node* head) {
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* next = NULL;
    
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    
        head = prev;  // Update the head pointer to the new head of the reversed list
        return head;
    }
    
    
    void addAtTail(struct Node** head, struct Node** tail, int data) {
        struct Node* newNode = new Node(data);
    
        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
            return;
        }

        (*tail)->next = newNode;
        *tail = newNode;
    }
    
    struct Node* solve(struct Node* first, struct Node* second){
    struct Node* ans = NULL;
    struct Node* ansTail = NULL; // Initialize ansTail to NULL
    int carry = 0;

    while (first != NULL || second != NULL) {
        int sum = carry;
        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }
        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        int decimal = sum % 10;
        carry = sum / 10;

        addAtTail(&ans, &ansTail, decimal);
    }

    if (carry > 0) {
        addAtTail(&ans, &ansTail, carry);
    }

    return reverseLL(ans);
    }
    
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node* firstReverse = reverseLL(first);
        struct Node* secondReverse = reverseLL(second);
        return solve(firstReverse ,secondReverse );
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends