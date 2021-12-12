#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int minVal = nums[i], maxVal = nums[i];
            for (int j = i; j < nums.size(); j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                sum += maxVal - minVal;
            }
        }
        return sum;
    }
};