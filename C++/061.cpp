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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL) return head;
        ListNode *pro= new ListNode(0);
        pro->next = head;
        ListNode *first=pro, *second=pro, *count=pro;
        // 计算链表结点数目，并对k取模
        int len =0;
        while(count->next)
        {
            len++;
            count=count->next;
        }
        k%=len;
        // 分开前后指针
        while(k-- && first->next)
        {
            first = first->next;
        }
        // 不需要调整
        if(first == second) return head;
        // 双指针记录
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *tem=second->next;
        second->next = NULL;
        first->next = pro->next;
        pro->next = tem;
        return pro->next;
    }
};