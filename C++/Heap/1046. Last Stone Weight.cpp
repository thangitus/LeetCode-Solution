#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int a, b;
            a = heap.top(), heap.pop();
            b = heap.top(), heap.pop();
            if (a != b) heap.push(a - b);
        }
        return heap.empty() ? 0 : heap.top();
    }
};
