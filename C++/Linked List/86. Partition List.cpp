#include "ListNode.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *cur = head, *left = new ListNode(), *right = new ListNode(), *tmp = right;
        head = left;
        while (cur) {
            if (cur->val < x)
                left->next = cur, left = cur;
            else right->next = cur, right = cur;
            cur = cur->next;
        }
        right->next = nullptr;
        left->next = tmp->next;
        return head->next;
    }
};
