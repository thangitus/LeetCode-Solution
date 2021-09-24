#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/palindromic-substrings/
 * Same idea with: Longest Palindromic Substring
 * dp[i][j] meaning substring from i..j is palindrome or not
 * */

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), result = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++) {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);
                result += dp[i][j];
            }
        return result;
    }
};
