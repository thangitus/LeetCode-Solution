#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int> &cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) dp[i][i] = 0;
        for (int i = size - 1; i >= 0; --i)
            for (int j = i + 1; j < size; ++j)
                for (int k = i + 1; k < j; ++k) {
                    if (dp[i][j] == 0) dp[i][j] = INT_MAX;
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
        return dp[0][size - 1];
    }
};
