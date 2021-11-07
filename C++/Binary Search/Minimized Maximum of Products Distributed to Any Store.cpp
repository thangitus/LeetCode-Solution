#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/advantage-shuffle/
 */

class Solution {
public:
    bool check(long long mid, int n, vector<int> &quantities) {
        int count = 0;
        for (auto x:quantities)
            count += x / mid + int(x % mid != 0);
        return count <= n;
    }

    int minimizedMaximum(int n, vector<int> &quantities) {
        long long left = 1, right = 1e10 + 1, result = right;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, n, quantities)) {
                result = mid;
                right = mid;
            } else left = mid + 1;
        }
        return result;
    }
};
