#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-the-winner-of-the-circular-game/
 * dp[i]: index of winner with i people
 * */

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            dp[i] = (dp[i - 1] + k) % i;
        return dp.back() + 1;
    }
};
