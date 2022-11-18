#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int curSum = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            curSum += arr[i];
            if (i >= k) curSum -= arr[i - k];
            if (i >= k - 1)res += (curSum / k >= threshold);
        }
        return res;
    }
};