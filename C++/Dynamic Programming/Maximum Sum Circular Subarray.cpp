#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-sum-circular-subarray/
 * */

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int sum = 0, n = nums.size(), curr1, curr2, max_sum, min_sum;
        curr1 = curr2 = max_sum = min_sum = nums[0];
        for (int i = 0; i < n; i++)sum += nums[i];
        for (int i = 1; i < n; i++) {
            curr1 = max(curr1 + nums[i], nums[i]);
            max_sum = max(curr1, max_sum);
            curr2 = min(curr2 + nums[i], nums[i]);
            min_sum = min(min_sum, curr2);
        }
        return max_sum > 0 ? max(max_sum, sum - min_sum) : max_sum;
    }
};
