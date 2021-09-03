#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/unique-binary-search-trees/
 * Refs: https://www.youtube.com/watch?v=OIc0mHgHUww
 * */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        return dp[n];
    }
};
