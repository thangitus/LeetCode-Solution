#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int> &nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int index = i - count;
            if (index % 2) continue;
            if (nums[i] == nums[i + 1])
                count++;
        }
        if ((nums.size() - count) % 2) count++;
        return count;
    }
};
