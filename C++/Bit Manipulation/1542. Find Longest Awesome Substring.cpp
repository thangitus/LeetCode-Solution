#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length(), mask = 0, res = 0;
        vector<int> seen(1024, n);
        seen[0] = -1;
        for (int i = 0; i < n; ++i) {
            mask ^= (1 << (s[i] - '0'));
            res = max(res, i - seen[mask]);
            for (int j = 0; j <= 9; ++j)
                res = max(res, i - seen[mask ^ (1 << j)]);
            seen[mask] = min(seen[mask], i);
        }
        return res;
    }
};