#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctAverages(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        unordered_set<double> seen;
        while (left < right) {
            seen.insert((nums[right] + nums[left]) / 2.0);
            left++, right--;
        }
        return seen.size();
    }
};