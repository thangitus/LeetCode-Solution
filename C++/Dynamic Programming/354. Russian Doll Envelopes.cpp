#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool compare(vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> height(n), sub;
        for (int i = 0; i < n; ++i)
            height[i] = envelopes[i][1];
        sub.push_back(height[0]);
        for (int i = 1; i < n; ++i)
            if (height[i] > sub.back())
                sub.push_back(height[i]);
            else {
                int index = lower_bound(sub.begin(), sub.end(), height[i]) - sub.begin();
                sub[index] = height[i];
            }
        return sub.size();
    }
};
