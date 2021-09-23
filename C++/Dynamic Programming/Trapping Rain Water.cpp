#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/trapping-rain-water/
 * */

class Solution {
public:
    int trap(vector<int> &height) {
        int result = 0, n = height.size();
        vector<int> left(n, INT_MIN), right(n, INT_MIN);
        left[0] = height[0], right.back() = height.back();
        for (int i = 1; i < n; i++) left[i] = max(left[i - 1], height[i]);
        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i + 1], height[i]);
        for (int i = 1; i < height.size() - 1; i++) result += min(left[i], right[i]) - height[i];
        return result;
    }
};
