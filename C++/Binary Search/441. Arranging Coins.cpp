#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n, mid, total;
        while (left <= right) {
            mid = left + (right - left) / 2;
            total = mid * (mid + 1) / 2;
            if (total == n) return mid;
            if (n < total) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};
