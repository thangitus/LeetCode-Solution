#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<int> maxHeap;
        unordered_map<int, int> deleted;
        for (int i = 0; i < n; ++i) {
            while (!maxHeap.empty() && deleted[maxHeap.top()])
                deleted[maxHeap.top()]--, maxHeap.pop();
            if (i >= k) deleted[dp[i - k]]++;
            dp[i] = nums[i] + (maxHeap.empty() ? 0 : maxHeap.top());
            maxHeap.push(dp[i]);
        }
        return dp[n - 1];
    }
};
