#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/merge-intervals/
 * */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int n = result.size() - 1;
            if (result[n][1] < intervals[i][0]) result.push_back(intervals[i]);
            else result[n][1] = max(result[n][1], intervals[i][1]);
        }
        return result;
    }
};
