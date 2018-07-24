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
    // 不断从一个链表中取出节点插入另一个链表
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* pre = new ListNode(0);
        ListNode* worker = head, *ender = head, *nower = head;
        while(ender != NULL)
        {
            ender = ender->next;
            nower = pre;
            // 寻找位置
            while(nower -> next != NULL && nower->next->val < worker->val)
                nower = nower->next;
            // 插入节点
            worker->next = nower->next;
            nower->next = worker;
            worker = ender;
        }
        return pre->next;
    }
};