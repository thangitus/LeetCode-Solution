#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/lexicographical-numbers/
 */

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        dfs(result, 0, n);
        return result;
    }

    void dfs(vector<int> &result, int cur, int &n) {
        for (int i = 0; i <= 9; i++) {
            int val = cur * 10 + i;
            if (val == 0) continue;
            if (val > n) return;
            result.push_back(val);
            dfs(result, val, n);
        }
    }
};