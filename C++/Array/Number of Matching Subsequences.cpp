#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/number-of-matching-subsequences/
 */

class Solution {
public:
    int numMatchingSubseq(string s, vector<string> &words) {
        vector<pair<int, int>> waitings[128];
        for (int i = 0; i < words.size(); i++)
            waitings[words[i][0]].emplace_back(i, 1);
        for (char c:s) {
            auto waiting = waitings[c];
            waitings[c].clear();
            for (auto it:waiting)
                waitings[words[it.first][it.second++]].push_back(it);
        }
        return waitings[0].size();
    }
};