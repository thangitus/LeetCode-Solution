#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<int> times(1001);
        for (auto &trip: trips) {
            times[trip[1]] += trip[0];
            times[trip[2]] -= trip[0];
        }
        int cur = 0;
        for (int i = 0; i <= 1000; i++) {
            cur += times[i];
            if(cur>capacity) return false;
        }
        return true;
    }
};
