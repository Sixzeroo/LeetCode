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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tem1 = headA, *tem2 = headB;
        while(tem1 != tem2)
        {
            tem1 = tem1 ? tem1->next : headA;
            tem2 = tem2 ? tem2->next : headB;
        }
        return tem1;
    }
};