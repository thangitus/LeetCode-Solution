#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int> &nums) {
        int result = -1, minVal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > minVal)
                result = max(result, nums[i] - minVal);
            minVal = min(minVal, nums[i]);
        }
        return result;
    }
};
