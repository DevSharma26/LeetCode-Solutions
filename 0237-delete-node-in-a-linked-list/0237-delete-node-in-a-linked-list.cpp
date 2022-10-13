/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
void deleteNode(ListNode* node) {

    //using delete function
    ListNode*current=node->next;
    node->val=current->val;
    node->next=current->next;
    delete(current);
}
};