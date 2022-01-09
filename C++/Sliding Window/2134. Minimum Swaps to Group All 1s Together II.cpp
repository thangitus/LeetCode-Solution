#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int> &nums) {
        int n = nums.size(), countOne = 0;
        for (int i = 0; i < n; ++i)
            countOne += nums[i];
        if (countOne == 0) return 0;
        for (int i = 0; i < n; ++i)
            nums.push_back(nums[i]);
        int maxOne = countOne, result = maxOne;
        countOne = 0;
        for (int i = 0; i < maxOne; ++i) countOne += nums[i];
        for (int right = maxOne; right < nums.size(); right++) {
            result = min(result, maxOne - countOne);
            countOne += nums[right];
            countOne -= nums[right - maxOne];
        }
        return result;
    }
};
