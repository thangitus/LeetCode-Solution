#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/palindrome-linked-list/
 */

class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head) {
        auto fast = head, low = head;
        while (fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
        }
        if (fast)low = low->next;
        low = reverse(low);
        fast = head;
        while (low) {
            if (low->val != fast->val) return false;
            low = low->next;
            fast = fast->next;
        }
        return true;
    }
};