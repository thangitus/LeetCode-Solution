#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/next-greater-node-in-linked-list/
 * </p>
 * Push nodes' values to vector<int> res.
 * stack will save the indices of elements that need to find next greater element.
 * In the end, we reset 0 to all elements that have no next greater elements.
 * */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> res;
        stack<int> stack;
        for (ListNode *node = head; node; node = node->next) {
            while (!stack.empty() && res[stack.top()] < node->val) {
                res[stack.top()] = node->val;
                stack.pop();
            }
            stack.push(res.size());
            res.push_back(node->val);
        }
        while (!stack.empty()) {
            res[stack.top()] = 0;
            stack.pop();
        }
        return res;
    }
};
