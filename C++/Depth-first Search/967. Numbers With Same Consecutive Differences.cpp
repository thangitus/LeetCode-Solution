#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> res;
    int n, k;

    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n, this->k = k;
        for (int i = 1; i <= 9; ++i)
            dfs(i, 1);

        return res;
    }

    void dfs(int cur, int len) {
        if (len == n) {
            res.push_back(cur);
            return;
        }
        int prev = cur % 10;
        if (prev - k >= 0)
            dfs(cur * 10 + prev - k, len + 1);
        if (prev + k <= 9 && k)
            dfs(cur * 10 + prev + k, len + 1);
    }
};