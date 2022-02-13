#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (isValid(n, index, mid, maxSum))
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    long isValid(int n, int index, int val, int maxSum) {
        int left = max(val - index, 0);
        long res = long(val + left) * (val - left + 1) / 2;
        int right = max(val - ((n - 1) - index), 0);
        res += long(val + right) * (val - right + 1) / 2;
        return (res - val) <= maxSum;
    }
};
