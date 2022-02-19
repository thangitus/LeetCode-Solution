#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int> &nums) {
        int minVal = INT_MAX, result = INT_MAX;
        priority_queue<int> maxHeap;
        for (int num: nums) {
            int n = num & 1 ? num * 2 : num;
            minVal = min(minVal, n);
            maxHeap.push(n);
        }
        while (maxHeap.top() % 2 == 0) {
            int top = maxHeap.top();
            maxHeap.pop();
            result = min(result, top - minVal);
            minVal = min(minVal, top / 2);
            maxHeap.push(top / 2);
        }
        return min(result, maxHeap.top() - minVal);
    }
};
