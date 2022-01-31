#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int> &nums, int original) {
        vector<bool> exist(1001);
        for (int &num: nums)
            exist[num] = true;
        while (original <= 1000 && exist[original])
            original *= 2;
        return original;
    }
};
