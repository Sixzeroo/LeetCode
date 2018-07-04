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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* z= new ListNode(0);
        z->next=head;
        ListNode* temp=z;
        int i;
        for(i=0;i<m-1;i++){
            temp=temp->next;
        }
        ListNode* curr=temp->next;
        ListNode* nex;
        ListNode* prev=NULL;
        for(int j=0;j<n-m+1;j++){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        ListNode* tail=temp->next;
        temp->next=prev;
        tail->next=curr;
        return z->next;
    }
};