#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/jump-game-ii/
 * */

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= nums[i]; j++)
                if (i + j < n)
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
        return dp.back();
    }
};
