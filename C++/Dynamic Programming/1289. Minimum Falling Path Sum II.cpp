#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<int> dp = arr[0];
        for (int i = 1; i < n; ++i) {
            int firstMin = INT_MAX, secondMin = INT_MAX, firstMinId;
            for (int j = 0; j < n; ++j)
                if (dp[j] < firstMin)
                    firstMin = dp[j], firstMinId = j;

            for (int j = 0; j < n; ++j)
                if (j != firstMinId && dp[j] < secondMin)
                    secondMin = dp[j];

            for (int j = 0; j < n; ++j)
                dp[j] = arr[i][j] + (j == firstMinId ? secondMin : firstMin);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
