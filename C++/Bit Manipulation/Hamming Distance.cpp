#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/hamming-distance/
 * */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x || y) {
            result += (x & 1) ^ (y & 1);
            x >>= 1, y >>= 1;
        }
        return result;
    }
};
