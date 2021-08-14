#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
 * */

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int k) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int &x:arr) {
            dp[x] = dp[x - k] + 1;
            res = max(res, dp[x]);
        }
        return res;
    }
};