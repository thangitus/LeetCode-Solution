#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        unordered_set<int> set;
        for (int &num: nums) if (num) set.insert(num);
        return set.size();
    }
};
