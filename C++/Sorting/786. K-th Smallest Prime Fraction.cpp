#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool compare(pair<int, int> &a, pair<int, int> &b) {
        double v1 = a.first * 1.0 / a.second;
        double v2 = b.first * 1.0 / b.second;
        return v1 < v2;
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        int n = arr.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                pairs.push_back({arr[i], arr[j]});
        sort(pairs.begin(), pairs.end(), compare);
        return {pairs[k - 1].first, pairs[k - 1].second};
    }
};
