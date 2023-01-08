#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int> &nums) {
        int count[2]{0};
        for (int num: nums)
            if (num < 0) count[0]++;
            else if (num > 0) count[1]++;
        return max(count[0], count[1]);
    }
};
