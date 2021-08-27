#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shortest-distance-to-a-character/
 * */

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.length(), INT_MAX);
        for (int i = 0, pos = -1; i < s.length(); i++) {
            if (s[i] == c) pos = i;
            if (pos != -1) ans[i] = i - pos;
        }
        for (int i = s.length() - 1, pos = -1; i >= 0; i--) {
            if (s[i] == c) pos = i;
            if (pos != -1) ans[i] = min(ans[i], pos - i);
        }
        return ans;
    }
};
