#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/remove-linked-list-elements/
 */

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        while (head && head->val == val) head = head->next;
        ListNode *prev, *curr = head;
        while (curr) {
            if (curr->val == val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        return head;
    }
};