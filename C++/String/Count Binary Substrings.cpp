#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-binary-substrings/
 * */

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur, prev, ans;
        prev = ans = 0;
        cur = 1;
        for (int i = 1; i < s.length(); i++)
            if (s[i] == s[i - 1])cur++;
            else {
                ans += min(cur, prev);
                prev = cur;
                cur = 1;
            }
        return ans + min(cur, prev);
    }
};