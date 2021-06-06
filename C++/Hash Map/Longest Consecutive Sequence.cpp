#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-consecutive-sequence/
 * */

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> map;
        int ans = 0;
        for (int &i:nums) {
            if (map[i] == 0) {
                int left = map[i - 1];
                int right = map[i + 1];
                map[i] = left + right + 1;
                map[i + right] = map[i];
                map[i - left] = map[i];
                ans = max(ans, map[i]);
            }
        }
        return ans;
    }
};
