#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &nums) {
        int n = nums.size(), countZero = 0, countOne = 0, curZero = 0, curOne = 0, maxResult = 0;
        for (int &num: nums) {
            countZero += num == 0;
            countOne += num == 1;
        }
        vector<int> result;
        for (int i = 0; i <= n; ++i) {
            int score = curZero + countOne - curOne;
            if (score > maxResult) {
                result.clear();
                result.push_back(i);
                maxResult = score;
            } else if (score == maxResult)
                result.push_back(i);
            if (i < n) {
                curZero += nums[i] == 0;
                curOne += nums[i] == 1;
            }
        }
        return result;
    }
};
