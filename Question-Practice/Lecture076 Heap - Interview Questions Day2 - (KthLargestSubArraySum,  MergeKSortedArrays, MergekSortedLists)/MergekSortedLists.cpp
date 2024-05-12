//https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772

#include <queue>
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

class NodeCompare {
public:
    bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

Node *mergeKLists(vector<Node *> &listArray) {
    priority_queue<Node *, vector<Node *>, NodeCompare> pq;

    int k = listArray.size();
    if (k == 0)
        return NULL;

    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            pq.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (pq.size() > 0) {
        Node *minimum = pq.top();
        pq.pop(); 
        
        if (minimum->next != NULL) {
            pq.push(minimum->next);
        }

        if (head == NULL) {
            head = minimum;
            tail = minimum;
        } else {
            tail->next = minimum;
            tail = minimum;
        }
    }

    return head;
}
