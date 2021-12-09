#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> map;
public:
    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]].push_back(i);
    }

    int pick(int target) {
        int size = map[target].size(), index = rand() % size;
        return map[target][index];
    }
};
