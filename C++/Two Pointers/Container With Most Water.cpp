#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/container-with-most-water/
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        int result = 0, l = 0, r = height.size() - 1;
        while (l <= r) {
            result = max(min(height[l], height[r]) * (r - l), result);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return result;
    }
};
