#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int averageValue(vector<int> &nums) {
        int sum = 0, count = 0;
        for (int &num: nums)
            if (num % 6 == 0) count++, sum += num;
        return count ? sum / count : 0;
    }
};