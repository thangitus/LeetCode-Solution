#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
// https://leetcode.com/problems/linked-list-cycle/
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