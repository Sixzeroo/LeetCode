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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head; 
        ListNode* prev = NULL; 
        ListNode* slow = head; 
        ListNode* fast = head; 
        while(fast && fast->next){
            prev = slow;
            slow = slow->next; 
            fast = fast->next->next; 
        }
        ListNode* mid = slow; 
        prev->next = NULL; // 对链表做截断处理
        
        ListNode* l = sortList(head); // 对截断后的左右两段链表分别做递归排序处理
        ListNode* r = sortList(mid);
        return mergeList(l,r); // 合并排序后的前后两段链表合并
    }
private: 
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* guard = new ListNode(0); 
        ListNode* cur = guard; 
        while(l1 && l2){
            if (l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next; 
            }
            else{
                cur->next = l2; 
                l2 = l2->next; 
            }
            cur = cur->next; 
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2; 
        return guard->next; 
    }
};