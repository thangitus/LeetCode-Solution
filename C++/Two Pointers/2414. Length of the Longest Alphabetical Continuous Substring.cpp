#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int left = 0, res = 1;
        for (int i = 1; i < s.length(); ++i)
            if (s[i] - s[i - 1] == 1)
                res = max(res, i - left + 1);
            else left = i;

        return res;
    }
};