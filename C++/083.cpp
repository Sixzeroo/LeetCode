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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* tem = head;
        while(tem != NULL)
        {
            while(tem -> next != NULL && tem -> next -> val == tem->val)
                tem -> next = tem->next->next;
            tem = tem->next;
        }
        return head;
    }
};