#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper) {
        long long prev = 0, minVal = 0, maxVal = 0;
        for (int &diff: differences) {
            auto val = prev + diff;
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
            prev = val;
        }
        return max(0LL, (upper - lower + 1) - (maxVal - minVal));
    }
};
