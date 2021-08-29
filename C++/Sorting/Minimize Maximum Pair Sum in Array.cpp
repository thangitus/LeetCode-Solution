#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
 * */

class Solution {
public:
    int minPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, n = nums.size(); i < n / 2; i++)
            res = max(res, nums[i] + nums[n - i - 1]);
        return res;
    }
};
