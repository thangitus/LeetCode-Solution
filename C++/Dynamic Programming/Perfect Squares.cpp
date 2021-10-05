#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/perfect-squares/
 * */

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares, dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= 10000; i++)
            squares.push_back(i * i);
        int index = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= squares[index + 1]) index++; //can use square[index+1]
            for (int j = 0; j <= index; j++) // traversal all square number <=i
                dp[i] = min(dp[i - squares[j]] + 1, dp[i]);
        }
        return dp[n];
    }
};
