#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int k) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); j++)
                result += (nums[i] == nums[j] && i * j % k == 0);
        return result;
    }
};
