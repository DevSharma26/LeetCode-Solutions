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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode** p = &head;
        ListNode*  next = head;
        while(n-- && next) next=next->next;
        while(next)
        {
           p = &(*p)->next;
           next=next->next;
        }
        *p = (*p)->next;
        return head;
    }
};