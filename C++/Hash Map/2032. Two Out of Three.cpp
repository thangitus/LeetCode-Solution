#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        vector<bool> count1(101), count2(101), count3(101);
        vector<int> result;
        getCount(nums1, count1);
        getCount(nums2, count2);
        getCount(nums3, count3);
        for (int i = 1; i <= 100; ++i)
            if (count1[i] + count2[i] + count3[i] >= 2)
                result.push_back(i);
        return result;
    }

    void getCount(vector<int> &nums, vector<bool> &count) {
        for (int num: nums)
            count[num] = true;
    }
};
