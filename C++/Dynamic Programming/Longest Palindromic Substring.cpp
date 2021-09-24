#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 * dp[i][j] meaning substring from i..j is palindrome or not
 * dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])
 * */

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, maxLen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        string result;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++) {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);
                if (dp[i][j] && maxLen < j - i + 1)
                    start = i, maxLen = j - i + 1;
            }
        return s.substr(start, maxLen);
    }
};
