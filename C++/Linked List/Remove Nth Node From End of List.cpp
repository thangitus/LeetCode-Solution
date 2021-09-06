#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head, *slow = head;
        while (n--) fast = fast->next;
        if (!fast) return head->next;       // if fast is already null, it means we have to delete head itself. So, just return next of head
        while (fast->next)
            fast = fast->next, slow = slow->next;
        slow->next = slow->next->next; // remove the nth node from last
        return head;
    }
};

