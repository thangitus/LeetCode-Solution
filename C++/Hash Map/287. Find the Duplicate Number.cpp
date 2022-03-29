#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        unordered_set<int> mSet;
        for (int &num: nums) {
            if (mSet.count(num))return num;
            mSet.insert(num);
        }
        return nums[0];
    }
};