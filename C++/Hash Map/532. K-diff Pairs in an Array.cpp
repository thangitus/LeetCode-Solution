#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int &num: nums)
            count[num]++;
        int result = 0;
        for (auto &i: count) {
            if ((k && count.find(i.first + k) != count.end()) || (!k && i.second > 1))
                result++;
        }
        return result;
    }
};
