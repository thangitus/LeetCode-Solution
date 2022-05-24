#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), res = 0;
        vector<int> dp(n);
        for (int i = 1; i < n; ++i)
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                res = max(res, dp[i]);
            }
        return res;
    }
};
