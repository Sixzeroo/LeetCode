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
    // 翻转k个链表的k个节点，last表示后面接的节点
    ListNode* reverseKNode(ListNode* first, int k, ListNode* last)
    {
        ListNode *tmp, *a = first, *b = first->next;
        first->next = last;
        // 只要进行k-1次改变
        for(int i=0;i<k-1;++i)
        {
            tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
            
        }
        return a;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 添加头结点
        ListNode *pre = new ListNode(0);
        pre->next = head;
        
        ListNode *first = pre, * second = pre, *kth;
        while(1)
        {
            int end = 0;
            // kth表示翻转的k个节点中的最后一个
            kth = first->next;
            // 判断够不够k个节点
            for(int i=0;i<k;++i)
            {
                second = second->next;
                if(second == NULL)
                {
                    end = 1;
                    break;
                }
            }
            if(end)
                break;
            first->next = reverseKNode(first->next, k, second->next);
            first = second = kth ;
        }
        return pre->next;
    }
};