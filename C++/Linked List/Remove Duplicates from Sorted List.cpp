#include "ListNode.h"

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode *prev = head, *cur = head->next;
        while (cur) {
            if (prev->val == cur->val)
                prev->next = cur->next;
            else prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
