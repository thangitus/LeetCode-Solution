#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &nums) {
        unordered_map<int, vector<int>> map;
        int res = -1;
        for (int num: nums) {
            int d = 0, tmp = num;
            while (tmp) d += (tmp % 10), tmp /= 10;
            map[d].push_back(num);
        }
        for (auto &item: map) {
            auto &arr = item.second;
            int n = arr.size();
            if (n < 2) continue;
            std::sort(arr.begin(), arr.end());
            res = max(res, arr[n - 1] + arr[n - 2]);
        }
        return res;
    }
};