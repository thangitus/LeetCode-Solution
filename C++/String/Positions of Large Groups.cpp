#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/positions-of-large-groups/
 * */

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int large = 3;
        for (int i = 0; i < s.length(); i++) {
            int j = i;
            while (j < s.length() && s[i] == s[j]) j++;
            if (j - i >= large) ans.push_back({i, j - 1});
            i = j - 1;
        }
        return ans;
    }
};
