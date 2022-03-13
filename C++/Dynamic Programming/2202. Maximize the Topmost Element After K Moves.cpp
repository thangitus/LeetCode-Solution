#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumTop(vector<int> &nums, int k) {
        if (k == 0) return nums[0];
        if (k % 2 == 1 && nums.size() == 1) return -1;
        if (k > nums.size()) return *max_element(nums.begin(), nums.end());
        vector<int> push(k), pop(k);
        int curMax = nums[0];
        if (nums.size() > 1) pop[0] = nums[1];
        k = min(k, (int) nums.size());
        nums.push_back(0);
        for (int i = 1; i < k; i++) {
            push[i] = max(push[i - 1], curMax);
            pop[i] = nums[i + 1];
            curMax = max(nums[i], curMax);
        }
        return max(push.back(), pop.back());
    }
};