#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
 * */

class Solution {
public:
    int getLucky(string s, int k) {
        int nums = 0;
        for (char &ch:s) {
            int n = ch - 'a' + 1;
            nums += n / 10 + n % 10;
        }
        while (--k && nums > 9) {
            int tmp = 0;
            while (nums) {
                tmp += nums % 10;
                nums /= 10;
            }
            nums = tmp;
        }
        return nums;
    }
};
