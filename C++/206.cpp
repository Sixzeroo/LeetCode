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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* pre = NULL, *now = head, *last = head->next;
        while(last != NULL)
        {
            now->next = pre;
            pre = now;
            now = last;
            last = last->next;
        }
        now->next = pre;
        return now;
    }
};