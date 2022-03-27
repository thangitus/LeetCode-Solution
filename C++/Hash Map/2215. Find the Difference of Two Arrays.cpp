#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> seen1, seen2;
        vector<unordered_set<int>> result(2);
        for (int num: nums2)
            seen2.insert(num);
        for (int num: nums1) {
            if (!seen2.count(num))
                result[0].insert(num);
            seen1.insert(num);
        }
        for (int num: nums2)
            if (!seen1.count(num))
                result[1].insert(num);
        vector<vector<int>> ans(2);
        ans[0].insert(ans[0].begin(), result[0].begin(), result[0].end());
        ans[1].insert(ans[1].begin(), result[1].begin(), result[1].end());
        return ans;
    }
};
