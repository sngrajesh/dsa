// https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250
#include <bits/stdc++.h>

/****************************************************************/

// Following is the class structure of the LinkedListNode class:

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/*****************************************************************/

// //Method 1

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {

//   if (head == NULL || head->next == NULL) {
//     return head;
//   }

//   LinkedListNode<int> *prev = NULL;
//   LinkedListNode<int> *curr = head;

//   while (curr != NULL) {
//     LinkedListNode<int>* nextNode = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = nextNode;
//   }
//   return prev;
// }

/*****************************************************************/

// Method 2 : Recursion - ChatGPT
// void reverse(LinkedListNode<int> *head, LinkedListNode<int> *curr, LinkedListNode<int> *&newHead, LinkedListNode<int> *prev)
// {
//     if (curr->next == NULL)
//     {
//         newHead = curr;
//         curr->next = prev;
//         return;
//     }
//     reverse(head, curr->next, newHead, curr);
//     curr->next = prev;
// }

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     LinkedListNode<int> *newHead = NULL; // to store the new head of the reversed list
//     LinkedListNode<int> *prev = NULL;
//     LinkedListNode<int> *curr = head;
//     reverse(head, curr, newHead, prev);
//     return newHead; // returning the new head of the reversed list
// }


//Method 2 : Recursion - Rajesh

// void reverse(LinkedListNode<int>* &head, LinkedListNode<int> *curr, LinkedListNode<int> *prev) {
//     if (curr->next == NULL) {
//         curr->next = prev;
//         head = curr;
//         return;
//     } 
//     reverse(head, curr->next, curr);
//     curr->next = prev;
// }

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     LinkedListNode<int> *prev = NULL;
//     reverse(head, head, prev);
//     return head;
// }

/*****************************************************************/