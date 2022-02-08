#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int> &nums, int target, int start) {
        int left, right;
        left = right = start;
        while (left >= 0 || right < nums.size()) {
            if (left >= 0 && nums[left] == target)
                return abs(left - start);
            if (right < nums.size() && nums[right] == target)
                return abs(right - start);
            left--, right++;
        }
        return -1;
    }
};
