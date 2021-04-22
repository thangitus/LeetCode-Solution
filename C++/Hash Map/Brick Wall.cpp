#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/brick-wall/
 * */

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> map;
        for (auto &row:wall) {
            int width = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                width += row[i];
                map[width]++;
            }
        }
        int ans = 0;
        for (auto &item:map)
            ans = max(ans, item.second);
        return wall.size() - ans;
    }
};