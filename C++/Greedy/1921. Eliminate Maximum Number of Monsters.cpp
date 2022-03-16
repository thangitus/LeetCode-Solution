#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        int n = dist.size();
        vector<int> times(n);
        for (int i = 0; i < n; ++i)
            times[i] = ceil(1.0 * dist[i] / speed[i]);
        sort(times.begin(), times.end());
        for (int i = 0; i < n; ++i)
            if (i >= times[i]) return i;
        return n;
    }
};
