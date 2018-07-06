/*
*  需要O(1) 空间
*/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *end = new ListNode(0), *now = head, *tem = head;
        while(now != NULL && now != end)
        {
            tem = now->next;
            now->next = end;
            now = tem;
        }
        return now == NULL ? false : true;
    }
};

/*
*   不需要额外空间
*/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *first = head, *second = head;
        while(first != NULL && second != NULL)
        {
            first = first->next;
            if(first == NULL) break;
            first = first->next;
            second = second->next;
            if(first == second) return true;
        }
        return false;
    }
};