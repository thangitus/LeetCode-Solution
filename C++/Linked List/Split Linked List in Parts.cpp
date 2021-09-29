#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/split-linked-list-in-parts/
 */

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int len = 0;
        ListNode *curr = head, *prev = nullptr;
        vector<ListNode *> result(k, nullptr);
        while (curr) {
            len++;
            curr = curr->next;
        }
        int div = len / k, remain = len % k;
        curr = head;
        for (int i = 0; i < k && curr; i++, remain--) {
            result[i] = curr;
            for (int j = 0; j < div + (remain > 0); j++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
        }
        return result;
    }
};