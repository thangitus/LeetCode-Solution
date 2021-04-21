/*
 * https://leetcode.com/problems/reverse-linked-list/
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

/**
 * https://leetcode.com/problems/linked-list-cycle/
 * */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)return false;
        ListNode *low = head;
        ListNode *high = head->next;
        while (low && high && high->next) {
            if (low == high) return true;
            low = low->next;
            high = high->next->next;
        }
        return false;
    }
};