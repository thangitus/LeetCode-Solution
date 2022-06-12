#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int res = 0, sum = 0, left = 0;
        unordered_set<int> set;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (set.count(nums[right])) {
                set.erase(nums[left]);
                sum -= nums[left++];
            }
            set.insert(nums[right]);
            res = max(res, sum);
        }
        return res;
    }
};
