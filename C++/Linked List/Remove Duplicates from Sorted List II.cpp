#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        int val = head->val;
        ListNode *p = head->next;
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next; //duplicate and skip head, p with same value
            return deleteDuplicates(p);
        }
    }
};
