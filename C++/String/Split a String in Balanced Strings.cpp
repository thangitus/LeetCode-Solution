#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/split-a-string-in-balanced-strings/
 * */

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans, balance;
        ans = balance = 0;
        for (char &ch:s) {
            if (ch == 'L')
                balance++;
            else balance--;
            if (!balance) ans++;
        }
        return ans;
    }
};