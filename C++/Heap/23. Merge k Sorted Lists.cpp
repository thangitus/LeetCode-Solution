#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<>> minHeap;
        for (auto &item: lists)
            if (item) minHeap.push({item->val, item});

        ListNode *head = new ListNode(), *cur = head;
        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            cur->next = top.second;
            cur = cur->next;
            auto next = top.second->next;
            if (next)
                minHeap.push({next->val, next});
        }
        return head->next;
    }
};
