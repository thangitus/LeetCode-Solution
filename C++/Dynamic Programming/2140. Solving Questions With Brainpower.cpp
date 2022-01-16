#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        vector<long long> dp(n), curMax(n);
        curMax[n - 1] = dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i) {
            int next = i + questions[i][1] + 1;
            dp[i] = questions[i][0];
            if (next < n)dp[i] += curMax[next];
            curMax[i] = max(curMax[i + 1], dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
