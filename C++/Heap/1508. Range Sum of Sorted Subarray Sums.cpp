#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;

class Solution {
public:
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        left--, right--;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        long res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i)
            minHeap.push({nums[i], i});

        for (int i = 0; i <= right; ++i) {
            int num = minHeap.top().first, index = minHeap.top().second + 1;
            minHeap.pop();
            if (i >= left)
                res = (res + num) % mod;
            if (index < n)
                minHeap.push({(num + nums[index]) % mod, index});
        }
        return int(res);
    }
};