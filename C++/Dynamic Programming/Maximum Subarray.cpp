#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/maximum-subarray/
 * */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int currSum = 0, result = nums[0];
        for (int &num:nums) {
            currSum += num;
            result = max(result, currSum);
            currSum = max(currSum, 0);
        }
        return result;
    }
};
