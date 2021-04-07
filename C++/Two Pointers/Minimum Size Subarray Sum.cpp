#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 * */

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ans, sum, i;
        sum = i = 0;
        ans = INT_MAX;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};
