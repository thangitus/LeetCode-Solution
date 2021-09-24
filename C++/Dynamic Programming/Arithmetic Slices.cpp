#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/arithmetic-slices/
 * [1,3,5,7,9]
 * Dp2: 135
 * Dp3: 1357, 357
 * Dp4: 13579,3579,579
 * */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size(), result = 0;
        if (n < 3) return 0;
        vector<int> dp(n);
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
            result += dp[i];
        }
        return result;
    }
};
