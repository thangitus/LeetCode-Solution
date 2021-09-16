#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/delete-and-earn/
 * */

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        int maxVal = 0;
        unordered_map<int, int> value;
        for (int &x:nums) {
            value[x] += x;
            maxVal = max(maxVal, x);
        }
        vector<int> take(maxVal + 1), skip(maxVal + 1);
        for (int i = 1; i <= maxVal; i++) {
            skip[i] = max(take[i - 1], skip[i - 1]);
            take[i] = skip[i - 1] + value[i];
        }
        return max(take.back(), skip.back());
    }
};
