#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length(), sum = 0;
        for (char c: s1)sum += c;
        for (char c: s2)sum += c;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 2));
        for (int i = 1; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return sum - 2 * dp[len1][len2];
    }
};
