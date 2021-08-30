#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 * */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefixSum(n), result(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        for (int i = 0; i < n; i++) {
            int left = 0, right;
            if (i > 0) left = i * nums[i] - prefixSum[i - 1];
            right = (prefixSum.back() - prefixSum[i]) - (n - i - 1) * nums[i];
            result[i] = left + right;
        }
        return result;
    }
};
