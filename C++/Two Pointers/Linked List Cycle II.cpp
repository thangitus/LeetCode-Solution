#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/linked-list-cycle-ii/
 * l: length of loop
 * m: distance from head to node start of loop
 * k: distance from node start -> node which slow and fast meet each other
 * dist_fast = m + fast*l + k
 * dist_slow= m + slow*l + k
 * dist_fast = 2*dist_slow
 * m + fast*l + k = 2m + 2slow*l + 2k
 * 2slow*l-fast*l + m + k = 0
 * m = l(2slow - fast) - k
 * l(2slow - fast) is integer
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) return nullptr;
        ListNode *turtle = head, *hare = head;
        while (hare->next && hare->next->next) {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle) break;
        }
        if (hare != turtle) return nullptr;

        turtle = head;
        while (turtle != hare) {
            hare = hare->next;
            turtle = turtle->next;
        }
        return turtle;
    }
};