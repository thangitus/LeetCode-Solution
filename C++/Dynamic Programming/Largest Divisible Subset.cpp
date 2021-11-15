#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/largest-divisible-subset/
 * */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), path(n, -1), result;
        int maxId = 0;
        for (int i = 0; i < n; i++)
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                    if (dp[i] > dp[maxId]) maxId = i;
                }
            }
        while (maxId != -1) {
            result.push_back(nums[maxId]);
            maxId = path[maxId];
        }
        return result;
    }
};
