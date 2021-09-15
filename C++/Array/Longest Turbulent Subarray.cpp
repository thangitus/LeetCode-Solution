#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-turbulent-subarray/
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        int dec = 1, inc = 1, result = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } else inc = dec = 1;
            result = max({result, dec, inc});
        }
        return result;
    }
};
