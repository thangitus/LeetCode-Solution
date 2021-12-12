#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num: nums)sum += num;
        if (sum % 2) return false;
        vector<bool> dp(sum + 1);
        sum /= 2;
        dp[0] = true;
        for (int num: nums)
            for (int i = sum; i >= num; i--)
                dp[i] = dp[i] || dp[i - num];
        return dp[sum];
    }
};
