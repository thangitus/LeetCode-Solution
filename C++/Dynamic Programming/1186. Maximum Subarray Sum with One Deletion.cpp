#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &arr) {
        int n = arr.size(), result = INT_MIN, maxEnd[n], maxStart[n];
        result = maxEnd[0] = arr[0], maxStart[n - 1] = arr[n - 1];
        for (int i = 1; i < n; ++i) {
            maxEnd[i] = max(arr[i], maxEnd[i - 1] + arr[i]);
            result = max(result, maxEnd[i]);
        }
        for (int i = n - 2; i >= 0; --i)
            maxStart[i] = max(arr[i], maxStart[i + 1] + arr[i]);
        for (int i = 1; i < n - 1; ++i)
            result = max(result, maxEnd[i - 1] + maxStart[i + 1]);
        return result;
    }
};
