#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    // Create a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find and print the middle node
    Node *middle = findMiddle(head);
    std::cout << "Middle node: " << middle->data << std::endl;

    // Clean up dynamically allocated memory
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
