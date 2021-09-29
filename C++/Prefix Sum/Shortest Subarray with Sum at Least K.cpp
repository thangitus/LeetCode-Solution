#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
 * Refs: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque
 * */

class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), result = INT_MAX;
        vector<int> prefixSum(n + 1);
        deque<int> deque;
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        for (int i = 0; i <= n; i++) {
            while (!deque.empty() && prefixSum[i] - prefixSum[deque.front()] >= k) {
                result = min(result, i - deque.front());
                deque.pop_front();
            }
            while (!deque.empty() && prefixSum[i] <= prefixSum[deque.back()])
                deque.pop_back();
            deque.push_back(i);
        }
        return result != INT_MAX ? result : -1;
    }
};
