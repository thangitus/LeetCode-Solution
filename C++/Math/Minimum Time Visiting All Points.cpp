#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-time-visiting-all-points/
 * */

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int ans = 0;
        auto curr = points[0];
        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - curr[0]);
            int dy = abs(points[i][1] - curr[1]);
            int diagonal = min(dx, dy);
            dx -= diagonal;
            dy -= diagonal;
            ans += diagonal + dx + dy;
            curr = points[i];
        }
        return ans;
    }
};
