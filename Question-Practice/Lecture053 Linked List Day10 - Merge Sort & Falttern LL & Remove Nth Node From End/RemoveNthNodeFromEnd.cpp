// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */1
class Solution {
public:
    int getLength(ListNode* head){
        if(head == NULL) return 0;
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
            int size = getLength(head);
            int nodeToDelete = size - n;
            if(nodeToDelete == 0){
                ListNode* d = head;
                head = head->next;
                delete d;
                return head;   
            }
            ListNode* temp = head;
            for(int i = 0; i < nodeToDelete - 1; i++){
                temp = temp->next;
            }
            ListNode* d = temp->next;
            temp -> next = temp->next->next;
            delete d;
            return head;

    }
};
