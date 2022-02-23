#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        if (head->next == nullptr) return nullptr;
        auto slow = head, fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};