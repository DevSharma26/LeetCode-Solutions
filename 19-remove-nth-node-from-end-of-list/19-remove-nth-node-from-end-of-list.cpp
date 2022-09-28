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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios_base::sync_with_stdio(0);
        ListNode* slow = head,*fast = head;
        int cnt = 0;
        while(cnt<n-1){
            cnt++;
            fast = fast->next;
        }
        ListNode* prev = NULL;
        while(fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(!prev){
            head = head->next;
            return head;
        }
        else{
            prev->next = slow->next;
            return head;
        }
    }
};