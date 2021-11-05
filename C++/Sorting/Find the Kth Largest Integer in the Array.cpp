#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
 * */

class Solution {
private:
    static bool compare(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        return s1 < s2;
    }

public:
    string kthLargestNumber(vector<string> &nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size() - k];
    }
};
