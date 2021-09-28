#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/middle-of-the-linked-list/
 */

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *curr = head;
        int count = 0;
        while (curr && count != k) { // k+1 node
            curr = curr->next;
            count++;
        }
        if (k == count) {
            curr = reverseKGroup(curr, k);
            while (count--) {
                ListNode *temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }
        return head;
    }
};
