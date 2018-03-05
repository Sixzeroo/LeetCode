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
    ListNode* partition(ListNode* head, int x) {
        
        // 先拆分再合并
        ListNode *smallhead = new ListNode(0), *bighead = new ListNode(0);
        ListNode *small = smallhead , *big = bighead;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                small -> next = head;
                small = small -> next;   
            }
            else
            {
                big -> next = head;
                big = big -> next;
            }
            head = head -> next;
        }
        
        small -> next = bighead->next;
        big -> next = NULL;
        
        return smallhead->next;
    }
};