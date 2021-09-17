#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/jump-game/
 * */

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int reached = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (reached < i) return false;
            reached = max(reached, nums[i] + i);
        }
        return true;
    }
};
