#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), compare);
        int result = 1, prev = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= prev) continue;
            result++, prev = points[i][1];
        }
        return result;
    }
};
