#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sign-of-the-product-of-an-array/
 * */

class Solution {
public:
    int arraySign(vector<int> &nums) {
        int product = 1;
        for (int &num:nums) {
            if (!num) return 0;
            product *= num;
            if (product < 0) product = -1;
            else product = 1;
        }
        return product;
    }
};
