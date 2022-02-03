#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<long, int> count;
        int result = 0;
        for (int &num1: nums1)
            for (int &num2: nums2) {
                long sum = num1 + num2;
                count[sum]++;
            }
        for (int &num3: nums3)
            for (int &num4: nums4)
                result += count[-(num3 + num4)];
        return result;
    }
};
