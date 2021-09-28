#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/reorder-list/
 */

class Solution {
public:
    void reorderList(ListNode *head) {
        stack<ListNode *> stack;
        ListNode *cur = head;
        while (cur) {
            stack.push(cur);
            cur = cur->next;
        }
        cur = head;
        for (int i = stack.size() / 2; i > 0; i--) {
            ListNode *top = stack.top();
            stack.pop();
            top->next = cur->next;
            cur->next = top;
            cur = cur->next->next;
        }
        cur->next = nullptr;
    }
};
