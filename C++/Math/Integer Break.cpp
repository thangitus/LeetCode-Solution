#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/integer-break/
 * 7: 3 * 4 = 12
 * 8: 3 * 3 * 2 = 18
 * 9: 3 * 3 * 3 = 27
 * 10: 3 * 3 * 4 = 36
 * 11: 3 * 3 * 3 * 2 = 54
 * */

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        if (n % 3 == 0) return pow(3, n / 3);
        if (n % 3 == 1) return pow(3, (n / 3) - 1) * 4;
        return pow(3, n / 3) * 2;
    }
};
