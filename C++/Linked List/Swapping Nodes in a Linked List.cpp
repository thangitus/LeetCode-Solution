/*
 * https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 */
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *left = head;
        for (int i = 0; i < k - 1 && left; i++)
            left = left->next;
        ListNode *right = head;
        ListNode *low = left;
        while (low->next) {
            low = low->next;
            right = right->next;
        }
        swap(left->val, right->val);
        return head;
    }
};