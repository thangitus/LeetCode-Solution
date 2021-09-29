#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/greatest-sum-divisible-by-three/
 * */

class Solution {
public:
    int maxSumDivThree(vector<int> &nums) {
        vector<int> dp(3);
        for (int &num:nums) {
            vector<int> prev = dp;
            for (int &prevSum:prev) {
                int sum = prevSum + num;
                int index = sum % 3;
                dp[index] = max(dp[index], sum);
            }
        }
        return dp[0];
    }
};
