#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        vector<int> res;
        for (int &n: nums)if (n < pivot) res.push_back(n);
        for (int &n: nums)if (n == pivot) res.push_back(n);
        for (int &n: nums)if (n > pivot) res.push_back(n);
        return res;
    }
};