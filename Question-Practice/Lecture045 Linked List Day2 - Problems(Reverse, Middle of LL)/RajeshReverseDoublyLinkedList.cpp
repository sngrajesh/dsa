
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node *reverseDLL(Node *head) {

  if (head == NULL || head->next == NULL) {
    if (head->prev != NULL) {
      head->next = head->prev;
      head->prev = NULL;
    }
    return head;
  }

  Node *newHead = reverseDLL(head->next);
  Node *nextNode = head->next;
  head->next = head->prev;
  head->prev = nextNode;

  return newHead;
}
