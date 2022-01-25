#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int> &nums) {
        unordered_map<int, int> count;
        for (int &num: nums) count[num]++;
        vector<int> result;
        for (int &num: nums)
            if (count[num] == 1 && !count[num - 1] && !count[num + 1])
                result.push_back(num);
        return result;
    }
};
