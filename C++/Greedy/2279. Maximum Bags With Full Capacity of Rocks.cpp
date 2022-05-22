#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        vector<int> nums;
        for (int i = 0; i < capacity.size(); ++i)
            nums.push_back(capacity[i] - rocks[i]);
        int count = 0, i = 0;
        sort(nums.begin(), nums.end());
        while (additionalRocks >= 0 && i < nums.size()) {
            additionalRocks -= nums[i];
            if (additionalRocks >= 0)
                count++;
            i++;
        }
        return count;
    }
};