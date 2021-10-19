#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
            cur.push_back(candidates[i]);
            backtracking(candidates, cur, remain - candidates[i], i);
            cur.pop_back();
        }
    }
};