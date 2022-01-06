#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<pair<int, int>> times;
        for (auto &trip: trips) {
            times.emplace_back(trip[1], trip[0]);
            times.emplace_back(trip[2], -trip[0]);
        }
        sort(times.begin(), times.end());
        int cur = 0;
        for (auto item: times) {
            cur += item.second;
            if (cur > capacity) return false;
        }
        return true;
    }
};
