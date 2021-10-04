#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-the-town-judge/
 * */

class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trusts) {
        vector<int> count(n + 1);
        for (auto &trust:trusts) {
            count[trust[1]]++;
            count[trust[0]]--;
        }
        for (int i = 1; i <= n; i++)
            if (count[i] == n - 1)
                return i;
        return -1;
    }
};
