#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-sideway-jumps/
 * */

class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        int dp[] = {1, 0, 1};
        for (int obstacle: obstacles) {
            if (obstacle > 0) dp[obstacle - 1] = 1e6;
            for (int i = 0; i < 3; ++i)
                if (obstacle != i + 1)
                    dp[i] = min({dp[i], dp[(i + 1) % 3] + 1, dp[(i + 2) % 3] + 1});
        }
        return min({dp[0], dp[1], dp[2]});
    }
};
