#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/max-points-on-a-line/
 * */

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int result = 1;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> counts;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0])
                    counts[DBL_MAX]++;
                else counts[double(points[i][1] - points[j][1]) / (points[i][0] - points[j][0])]++;
            }
            for (auto &item:counts)
                result = max(result, item.second + 1);
        }
        return result;
    }
};