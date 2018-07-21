/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode* tem = head, *after = head;
        // 复制
        while(tem != NULL)
        {
            after = tem->next;
            RandomListNode* new_node = new RandomListNode(tem->label);
            tem->next = new_node;
            new_node->next = after;
            tem = after;
        }
        // 复制随机指针
        tem = head, after = head;
        RandomListNode* res = head->next, *res_tem = head->next, *res_list = NULL;
        while(tem != NULL)
        {
            after = tem->next->next;
            res_tem = tem->next;
            res_tem->random = tem->random == NULL ? NULL : tem->random->next;
            tem = after;
        }
        // 分离两个链表
        tem = head, after = head;
        while(tem != NULL)
        {
            after = tem->next->next;
            res_tem = tem->next;
            if(res_list == NULL) res_list = res_tem;
            else {
                res_list->next = res_tem;
                res_list = res_list->next;
            }
            tem->next = after;
            tem = after;
        }
        return res;
    }
};