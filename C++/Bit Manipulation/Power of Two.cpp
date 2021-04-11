#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/power-of-two/
 * */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};