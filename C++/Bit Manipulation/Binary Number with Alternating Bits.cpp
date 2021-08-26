#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/binary-number-with-alternating-bits/
 * */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr = -1;
        while (n) {
            int d = n % 2;
            if (d == curr) return false;
            curr = d;
            n >>= 1;
        }
        return true;
    }
};
