#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;
        auto cur = head;
        int n = 1;
        while (cur->next)
            n++, cur = cur->next;
        cur->next = head;
        cur = head;
        k %= n;
        for (int i = 0; i < n - k - 1; ++i)
            cur = cur->next;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};
