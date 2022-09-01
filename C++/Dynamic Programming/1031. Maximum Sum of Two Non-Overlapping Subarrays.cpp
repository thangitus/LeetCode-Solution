#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        int n = nums.size(), res = INT_MIN;
        vector<int> prefixSum(n + 1);
        for (int i = 1; i <= n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        for (int i = firstLen; i <= n; ++i) {
            int firstSum = prefixSum[i] - prefixSum[i - firstLen];
            for (int j = i - firstLen; j >= secondLen; --j)
                res = max(res, firstSum + prefixSum[j] - prefixSum[j - secondLen]);
            for (int j = i + secondLen; j <= n; ++j)
                res = max(res, firstSum + prefixSum[j] - prefixSum[j - secondLen]);
        }
        return res;
    }
};
