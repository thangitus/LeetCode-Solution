#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 */

class Solution {
public:
    int findGCD(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = gcd(nums[0], nums.back());
        return res;
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};
