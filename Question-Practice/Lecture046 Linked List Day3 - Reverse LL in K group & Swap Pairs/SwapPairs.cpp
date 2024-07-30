// https://leetcode.com/problems/swap-nodes-in-pairs/submissions/1325158755/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;

        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next = head->next;
        head = head->next;
        while(next != NULL){
            temp->next = temp->next->next;
            next->next = temp;
            if(prev != NULL) 
                prev->next = next;
            prev = temp;
            if(prev->next != NULL){
                temp = prev->next;
                next = prev->next->next;
            }else{
                break; 
            }
        }

        return head;
    }
};
