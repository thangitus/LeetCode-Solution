#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> result(nums.size());
        int positive = 0, negative = 1;
        for (int &num: nums) {
            if (num < 0) result[negative] = num, negative += 2;
            else result[positive] = num, positive += 2;
        }
        return result;
    }
};
