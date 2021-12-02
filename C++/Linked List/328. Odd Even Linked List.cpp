#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = evenHead;
        return head;
    }
};