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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 在前面添加一个Node
        ListNode oth = ListNode(0);
        // 初始化遍历指针和删除指针
        ListNode *pre=&oth, *it=head;
        pre -> next = head;
        int dis = 0;
        // 依据距离确定删除的node
        while(it != NULL)
        {
            if(dis != n)
                ++dis;
            else
                pre = pre -> next;
            it = it->next;
        }
        pre -> next = pre->next->next;
        return oth.next;
    }
};