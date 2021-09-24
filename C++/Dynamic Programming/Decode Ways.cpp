#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/decode-ways/
 * */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[0] = s[0] != '0' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            int num = stoi(s.substr(i - 1, 2));
            if (num > 9 && num < 27) dp[i + 1] += dp[i - 1];
        }
        return dp.back();
    }
};
