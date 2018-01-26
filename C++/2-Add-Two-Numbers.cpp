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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ret=new ListNode(-1),*cur=ret;
        int carry =0;
        while(l1||l2)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            carry=sum/10;
            cur->next = new ListNode(sum%10);
            cur= cur->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry) cur->next = new ListNode (carry);
        return ret->next;
    }
};