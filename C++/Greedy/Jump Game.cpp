#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/jump-game/
 * */

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int maxStep = 0, n = nums.size(); //Mặc định có thể nhảy tới ô 0
        for (int i = 0; i < n; i++)
            if (maxStep >= i) maxStep = max(maxStep, i + nums[i]); //Nếu đã nhảy qua ô i thì có thể nhảy tới ô i + nums[i]
        return maxStep >= n - 1;
    }
};