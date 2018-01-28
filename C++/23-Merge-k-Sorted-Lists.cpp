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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        auto *cur = &dummy;

        struct Compare {
            bool operator() (const ListNode *a, const ListNode *b) {
                return a->val > b->val;
            }
        };

        // Use min heap to keep the smallest node of each list
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        for (const auto& n : lists) {
            if (n) {
                min_heap.emplace(n);
            }
        }

        while (!min_heap.empty()) {
            // Get min of k lists.
            auto *node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }
};