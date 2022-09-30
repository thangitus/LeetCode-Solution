#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        int n = buildings.size(), prevHeight = -1, curHeight, i = 0;
        priority_queue<pair<int, int>> queue;
        vector<vector<int>> res;
        while (i < n || !queue.empty()) {
            int curX = queue.empty() ? buildings[i][0] : queue.top().second;
            if (i >= n || buildings[i][0] > curX)
                while (!queue.empty() && queue.top().second <= curX) queue.pop();
            else {
                curX = buildings[i][0];
                while (i < n && buildings[i][0] == curX)
                    queue.push({buildings[i][2], buildings[i][1]}), i++;
            }
            curHeight = queue.empty() ? 0 : queue.top().first;
            if (curHeight != prevHeight)
                res.push_back({curX, curHeight});
            prevHeight = curHeight;
        }
        return res;
    }
};
