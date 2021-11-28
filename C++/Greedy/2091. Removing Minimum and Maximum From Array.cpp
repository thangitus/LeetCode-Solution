#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumDeletions(vector<int> &nums) {
        int n = nums.size(), minVal = INT_MAX, maxVal = INT_MIN, minId = -1, maxId = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minId = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                minId = i;
            }
        }
        int left = min(minId, maxId), right = max(minId, maxId), result = INT_MAX;
        result = min(result, left + n - right + 2);
        result = min(result, right + 1);
        result = min(result, n - left);
        return result;
    }
};