#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-square-numbers/
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while (left <= right) {
            long cur = left * left + right * right;
            if (cur == c) return true;
            if (cur < c) left++;
            else right--;
        }
        return false;
    }
};
