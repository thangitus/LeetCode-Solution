#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/power-of-three/
 * */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (int) pow(3, 19) % n == 0;
    }
};