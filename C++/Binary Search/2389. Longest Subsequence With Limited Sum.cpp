#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        int m = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<int> prefixSum(m), res;
        prefixSum[0] = nums[0];
        for (int i = 1; i < m; ++i) prefixSum[i] = prefixSum[i - 1] + nums[i];
        for (int q: queries) {
            int pos = lower_bound(prefixSum.begin(), prefixSum.end(), q) - prefixSum.begin();
            if (pos >= m) {
                res.push_back(m);
                continue;
            }
            if (prefixSum[pos] > q) pos--;
            res.push_back(pos + 1);
        }
        return res;
    }
};