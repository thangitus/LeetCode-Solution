#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0, leftSum = 0;
        for (int &num: nums) sum += num;
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
            if (leftSum == sum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
