#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        long long res = 0, left = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i]) left = i + 1;
            else res += (i - left + 1);
        return res;
    }
};
