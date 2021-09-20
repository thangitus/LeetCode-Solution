#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/product-of-array-except-self/
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int product = 1, countZero = 0;
        for (int &num:nums) {
            if (num) product *= num;
            else countZero++;
        }
        for (int &num:nums) {
            if (countZero > 1) {
                num = 0;
                continue;
            }
            if (num) {
                if (countZero) num = 0;
                else num = product / num;
            } else num = product;
        }
        return nums;
    }
};
