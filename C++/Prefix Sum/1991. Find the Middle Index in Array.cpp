#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> &nums) {
        int sum = 0, sumLeft = 0;
        for (int &num: nums) sum += num;
        for (int i = 0; i < nums.size(); ++i) {
            sum -= nums[i];
            if (sum == sumLeft) return i;
            sumLeft += nums[i];
        }
        return -1;
    }
};
