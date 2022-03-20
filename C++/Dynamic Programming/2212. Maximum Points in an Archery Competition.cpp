#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
        memo.resize(12, vector<int>(numArrows + 1, -1));
        vector<int> result(12);
        int remain = numArrows;
        dp(aliceArrows, 0, remain);
        for (int i = 0; i < 11; ++i)
            if (memo[i][remain] != memo[i + 1][remain])
                result[i] = aliceArrows[i] + 1, remain -= (aliceArrows[i] + 1);
        result[11] = remain;
        return result;
    }

    int dp(vector<int> &aliceArrows, int i, int remain) {
        if (remain <= 0) return 0;
        if (i >= 12) return 0;
        if (memo[i][remain] == -1) {
            int skip = dp(aliceArrows, i + 1, remain), take = 0;
            if (remain > aliceArrows[i])
                take = dp(aliceArrows, i + 1, remain - (aliceArrows[i] + 1)) + i;
            memo[i][remain] = max(take, skip);
        }
        return memo[i][remain];
    }
};
