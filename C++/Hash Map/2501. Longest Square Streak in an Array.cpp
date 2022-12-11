#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int res = -1;
        for (int n: nums) {
            int k = sqrt(n);
            if (dp[k] && k * k == n) {
                dp[n] = dp[k] + 1;
                res = max(res, dp[n]);
            } else dp[n] = 1;
        }
        return res;
    }
};