#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sums;

    Solution(vector<int> &w) {
        partial_sum(w.begin(), w.end(), back_inserter(sums));
    }

    int pickIndex() {
        int num = rand() % sums.back();
        return upper_bound(sums.begin(), sums.end(), num) - sums.begin();
    }
};
