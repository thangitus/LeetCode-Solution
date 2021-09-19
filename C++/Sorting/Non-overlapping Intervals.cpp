#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/non-overlapping-intervals/
 * */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0], cur;
        int result = 0;
        for (int i = 1; i < intervals.size(); i++) {
            cur = intervals[i];
            if (cur[0] < prev[1]) {
                result++;
                if (cur[1] <= prev[1]) prev = cur;
            } else prev = cur;
        }
        return result;
    }
};
