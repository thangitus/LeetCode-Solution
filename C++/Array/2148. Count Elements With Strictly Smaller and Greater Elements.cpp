#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &nums) {
        int minVal = INT_MAX, maxVal = INT_MIN, countMin = 0, countMax = 0;
        for (int &num: nums) {
            if (num == minVal) countMin++;
            else if (num < minVal)
                minVal = num, countMin = 1;
            if (num == maxVal) countMax++;
            else if (num > maxVal)
                maxVal = num, countMax = 1;
        }
        if (minVal == maxVal) return 0;
        return nums.size() - countMin - countMax;
    }
};
