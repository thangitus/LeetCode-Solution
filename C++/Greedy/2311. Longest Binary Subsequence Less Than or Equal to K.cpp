#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0, value = 0, pow = 1;
        for (int i = s.length() - 1; i >= 0 && value + pow <= k; --i) {
            if (s[i] == '1') {
                value += pow;
                cnt++;
            }
            pow <<= 1;
        }
        return count(s.begin(), s.end(), '0') + cnt;
    }
};
