#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * */

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int &num:nums1) map[num]++;
        for (int &num:nums2)
            if (map[num]) {
                result.push_back(num);
                map[num]--;
            }
        return result;
    }
};
