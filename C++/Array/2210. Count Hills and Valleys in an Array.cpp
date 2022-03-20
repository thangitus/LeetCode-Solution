#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int> &nums) {
        int result = 0;
        for (int i = 1; i < nums.size() - 1;) {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i])
                j++;
            if (nums[i] > nums[i - 1] && nums[i] > nums[j] && j < nums.size()) result++;
            if (nums[i] < nums[i - 1] && nums[i] < nums[j] && j < nums.size()) result++;
            i = j;
        }
        return result;
    }
};
