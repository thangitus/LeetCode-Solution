#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size(), res = -1;
        if (m * k > n) return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (isValid(bloomDay, m, k, mid)) right = mid - 1, res = mid;
            else left = mid + 1;
        }
        return res;
    }

    bool isValid(vector<int> &bloomDay, int m, int k, int x) {
        int left = 0, count = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= x) {
                if (i - left + 1 >= k) count++, left = i + 1;
            } else left = i + 1;
        }
        return count >= m;
    }
};