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
    void swapNode(ListNode *first)
    {
        ListNode *tmp1 = first -> next, *tmp2 = first->next->next, *tmp3=first->next->next->next;
        first -> next = tmp2 ;
        tmp2 -> next = tmp1;
        tmp1 -> next = tmp3;
    }
    
    ListNode* swapPairs(ListNode* head) {
        // 创建头节点
        ListNode *res = new ListNode(0) ;
        res->next = head;
        head = res;
        while(head != NULL)
        {
            if(head->next == NULL || head->next->next == NULL)
                break;
            else
            {
                swapNode(head);
                head = head->next->next;
            }
        }
        return res->next;
    }
};