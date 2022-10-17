#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int> &nums) {
        unordered_set<int> seen;
        int res = -1;
        for (int num: nums) {
            if (seen.count(-num))
                res = max(res, abs(num));
            seen.insert(num);
        }
        return res;
    }
};