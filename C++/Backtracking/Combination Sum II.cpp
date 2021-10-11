#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/combination-sum-ii/
*/

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, cur, target, 0);
        return result;
    }

    void backtracking(vector<int> &candidates, vector<int> &cur, int remain, int start) {
        if (remain == 0) {
            result.push_back(cur);
            return;
        }
        if (remain < 0) return;
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            cur.push_back(candidates[i]);
            backtracking(candidates, cur, remain - candidates[i], i + 1);
            cur.pop_back();
        }
    }
};
