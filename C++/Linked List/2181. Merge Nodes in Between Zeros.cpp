#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *prev = head, *cur = head->next;
        while (cur) {
            if (cur->val == 0) {
                if (cur->next)
                    prev->next = cur;
                else prev->next = nullptr;
                prev = cur;
            } else prev->val += cur->val;
            cur = cur->next;
        }
        return head;
    }
};