#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-happy-prefix/
 */

class Solution {
public:
    string longestPrefix(string s) {
        const long long int MOD = 1e+7;
        long long int pos = -1, len = s.length(), left[len + 1], right[len + 1], base = 31, p = 1;
        left[0] = 0, right[len] = 0;
        for (int i = 1; i <= len; i++)
            left[i] = (s[i - 1] - 'a' + 1 + base * left[i - 1]) % MOD;
        for (int i = len - 1; i >= 0; i--) {
            right[i] = ((s[i] - 'a' + 1) * p + right[i + 1]) % MOD;
            p = (1LL * p * base) % MOD;
        }
        for (int i = 1; i < len; i++)
            if (left[i] == right[len - i]) pos = i;
        if (pos == -1) return "";
        return s.substr(0, pos);
    }
};