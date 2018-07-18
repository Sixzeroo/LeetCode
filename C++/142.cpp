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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return NULL;
        ListNode *slow=head->next;
        ListNode *fast=head->next->next;
        while(slow!=fast){ //if slow pointer meets fast pointer, it means there exists a circle
            if(slow->next==NULL) return NULL;
            slow=slow->next;
            if(fast->next==NULL||fast->next->next==NULL) return NULL;
            fast=fast->next->next;
        }
        
        fast=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};