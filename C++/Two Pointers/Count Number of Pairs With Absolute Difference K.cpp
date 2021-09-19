#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
 * */

class Solution {
public:
    int countKDifference(vector<int> &nums, int k) {
        int n = nums.size(), result = 0, j = 0;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n;) {
            int num = nums[i], cnt = 0;
            while (i < n && nums[i] == num) ++i, ++cnt;
            while (j < n && nums[j] < num + k) ++j;
            int start = j;
            while (j < n && nums[j] <= num + k) ++j;
            result += (j - start) * cnt;
        }
        return result;
    }
};
