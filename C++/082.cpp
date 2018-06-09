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
    ListNode* deleteDuplicates(ListNode* head) {
        // 创建头节点
        ListNode* pre = new ListNode(0);
        pre->next = head;
        // 使用三个辅助节点
        ListNode *first = pre, *second = head, *thrid;
        while(second != NULL)
        {
            thrid = second->next;
            if(thrid == NULL) break;
            // 发现重复的时候，删除所有重复节点
            if(second->val == thrid->val)
            {
                while(thrid != NULL && second->val == thrid->val)
                {
                    thrid = thrid->next;
                    second->next = thrid;
                }
                first->next = thrid;
                second = thrid;
            }
            else
            {
                first = second;
                second = thrid;
            }
        }
        return pre->next;
    }
};