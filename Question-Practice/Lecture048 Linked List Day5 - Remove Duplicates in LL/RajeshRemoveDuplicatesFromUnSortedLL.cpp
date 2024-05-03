#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

Node *removeDuplicates2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    unordered_set<int> s;

    Node *ptr1 = head;
    s.insert(ptr1->data);

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        if (s.find(ptr1->next->data) != s.end())
        {
            Node *del = ptr1->next;
            ptr1->next = ptr1->next->next;
            delete (del);
        }
        else
        {
            s.insert(ptr1->next->data);
            ptr1 = ptr1->next;
        }
    }
    return head;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *push(Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return new_node;
}

int main()
{
    Node *head = NULL;

    push(&head, -1);
    push(&head, 3);
    push(&head, 3);
    push(&head, 3);
    push(&head, 3);
    push(&head, 3);

    printList(head);
    head = removeDuplicates2(head);
    printList(head);

    return 0;
}
