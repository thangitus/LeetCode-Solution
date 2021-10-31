#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 */

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> pos, result(2, -1);
        int prev = head->val, step = 0;
        ListNode *cur = head->next;
        while (cur->next) {
            int val = cur->val;
            step++;
            if ((val > prev && val > cur->next->val) || (val < prev && val < cur->next->val))
                pos.push_back(step);
            prev = val;
            cur = cur->next;
        }
        if (pos.size() < 2) return result;
        result[0] = result[1] = pos.back() - pos[0];
        for (int i = 1; i < pos.size(); i++)
            result[0] = min(result[0], pos[i] - pos[i - 1]);
        return result;
    }
};