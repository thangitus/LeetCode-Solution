#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (int &num: arr1) {
            auto upper = upper_bound(arr2.begin(), arr2.end(), num + d);
            auto lower = lower_bound(arr2.begin(), arr2.end(), num - d);
            res += upper == lower;
        }
        return res;
    }
};
