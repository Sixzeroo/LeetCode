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
    // 简单但是空间复杂度不是最优的
    void reorderList(ListNode* head) {
        if (!head or !head->next) return;
        ListNode *temp=head;
        vector<ListNode *> s;
        int count=0,half=1;
        while (temp) {
            s.push_back(temp);
            temp=temp->next;
            count++;
        }
        temp=head;
        while (half<=count/2) {
            ListNode *next=temp->next;
            temp->next=s.back();
            s.back()->next=(count%2==0 and half==count/2) ? NULL : next;
            s.pop_back();
            temp=next;
            half++;
        }
        temp->next=NULL;
    }
};