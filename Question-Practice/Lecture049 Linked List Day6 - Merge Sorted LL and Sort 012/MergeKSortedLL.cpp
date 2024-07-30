// https://leetcode.com/problems/merge-k-sorted-lists/description/


#include<queue>
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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp>pq;  
        
        for(ListNode* head:lists){
            if (head) pq.push(head);
        }      

        ListNode dummy(0);
        ListNode* head = &dummy;
        
        while(!pq.empty()){ 
            head->next = pq.top(); pq.pop();
            head = head->next;
            if (head->next) pq.push(head->next);
        }
        return dummy.next;
    }
};
