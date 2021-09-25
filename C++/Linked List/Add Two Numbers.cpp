#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/merge-two-sorted-lists/
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return nullptr;
        else if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        int sum = l1->val + l2->val;
        auto *result = new ListNode(sum % 10);
        result->next = addTwoNumbers(l1->next, l2->next);
        if (sum >= 10) result->next = addTwoNumbers(result->next, new ListNode(1));
        return result;
    }
};
