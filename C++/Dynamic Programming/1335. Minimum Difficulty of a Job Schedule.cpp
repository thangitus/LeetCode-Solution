#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int minDifficulty(vector<int> &jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (n < d) return -1;
        dp = vector<vector<int>>(n + 1, vector<int>(d + 1, -1));
        return topDown(d, 0, jobDifficulty);
    }

    int topDown(int d, int index, vector<int> &jobDifficulty) {
        if (d == 0 && index == n) return 0;
        if (d == 0 || index == n) return 1e9;
        if (dp[index][d] == -1) {
            int result = INT_MAX, curMax = INT_MIN;
            for (int i = index; i < n; ++i) {
                curMax = max(curMax, jobDifficulty[i]);
                result = min(result, topDown(d - 1, i + 1, jobDifficulty) + curMax);
            }
            dp[index][d] = result;
        }
        return dp[index][d];
    }
};