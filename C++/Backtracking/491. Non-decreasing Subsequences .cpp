#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<int> cur;
        backtracking(cur, nums, 0);
        return res;
    }

    void backtracking(vector<int> &cur, vector<int> &nums, int idx) {
        if (cur.size() > 1) res.push_back(cur);
        unordered_set<int> seen;
        for (int i = idx; i < nums.size(); ++i) {
            if ((cur.empty() || cur.back() <= nums[i]) && !seen.count(nums[i])) {
                cur.push_back(nums[i]);
                backtracking(cur, nums, i + 1);
                cur.pop_back();
                seen.insert(nums[i]);
            }
        }
    }
};
