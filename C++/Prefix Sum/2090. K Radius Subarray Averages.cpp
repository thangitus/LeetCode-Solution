#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int> &nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1);
        vector<int> result(n, -1);
        for (int i = 1; i <= n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        for (int i = k; i < n - k; i++) {
            int right = i + k, left = i - k;
            auto sum = prefixSum[right + 1] - prefixSum[left];
            result[i] = sum / (k * 2 + 1);
        }
        return result;
    }
};
