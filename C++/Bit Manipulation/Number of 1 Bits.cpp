#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/number-of-1-bits/
 * */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
