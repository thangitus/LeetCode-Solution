#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int c: nums) {
            if (c <= a) a = c;
            else if (c <= b) b = c;
            else return true;
        }
        return false;
    }
};