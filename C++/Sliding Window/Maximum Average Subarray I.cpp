#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-average-subarray-i/
 * */

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int res, sum = 0, i = 0;
        for (; i < k; i++) sum += nums[i];
        res = sum;
        for (; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            res = max(res, sum);
        }
        return res / double(k);
    }
};
