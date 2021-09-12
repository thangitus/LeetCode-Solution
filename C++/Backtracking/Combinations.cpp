#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/combinations/
*/

class Solution {
public:
    vector<vector<int>> result;
    int n, k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> cur;
        combine(cur, 1);
        return result;
    }

    void combine(vector<int> &cur, int i) {
        if (cur.size() == k) {
            result.push_back(cur);
            return;
        }
        for (; i <= n; i++) {
            cur.push_back(i);
            combine(cur, i + 1);
            cur.pop_back();
        }
    }
};
