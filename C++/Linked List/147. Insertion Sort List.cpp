#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *cur, *tail = head, *iter;
        while (tail->next) {
            if (tail->val <= tail->next->val) {
                tail = tail->next;
                continue;
            }
            cur = tail->next;
            tail->next = tail->next->next;

            if (cur->val < head->val) {
                cur->next = head;
                head = cur;
                continue;
            }
            iter = head;
            while (iter != tail) {
                if (cur->val < iter->next->val) {
                    cur->next = iter->next;
                    iter->next = cur;
                    break;
                }
                iter = iter->next;
            }
        }
        return head;
    }
};
