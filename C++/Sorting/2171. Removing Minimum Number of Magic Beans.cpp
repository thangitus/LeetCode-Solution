#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int> &beans) {
        long long res = LLONG_MAX, n = beans.size(), sum = accumulate(beans.begin(), beans.end(), 0LL);
        sort(beans.begin(), beans.end());
        for (int i = 0; i < n; ++i) {
            auto remainSum = (n - i) * beans[i];
            auto deleted = sum - remainSum;
            res = min(res, deleted);
        }
        return res;
    }
};
