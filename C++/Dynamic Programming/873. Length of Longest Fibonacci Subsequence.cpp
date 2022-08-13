#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int> &nums) {
        int n = nums.size(), res = 0;
        map<int, int> index;
        for (int i = 0; i < n; i++) index[nums[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
                int c = nums[i], b = nums[j], a = c - b;
                if (index.count(a) && a < b)
                    dp[j][i] = max(dp[j][i], dp[index[a]][j] + 1);
            }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                res = max(res, dp[i][j]);

        return res > 2 ? res : 0;
    }
};
