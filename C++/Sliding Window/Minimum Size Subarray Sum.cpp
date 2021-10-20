#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 * */

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = INT_MAX, curSum = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            curSum += nums[right];
            while (curSum >= target) {
                result = min(result, right - left + 1);
                curSum -= nums[left++];
            }
        }
        return result != INT_MAX ? result : 0;
    }
};
