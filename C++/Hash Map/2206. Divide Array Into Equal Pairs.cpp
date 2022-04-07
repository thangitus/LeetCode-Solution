#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int> &nums) {
        unordered_map<int, int> count;
        for (int &num: nums)
            count[num]++;
        for (auto &item: count)
            if (item.second % 2) return false;
        return true;
    }
};
