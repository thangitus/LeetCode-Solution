#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * <p>
 * If remainder[i] = a, and remainder[j] = a (j < i). sums(remainder[j]..remainder[i]) = 0
 * => j -> i is a subarray with sum divisible by k.
 * </p>
 * Use map to calculate number of time remainder appear
 * <p>
 * </p>
 * To calculate remainder of current number, we use:
 * @code num % k + k @endcode
 * Because in C++ or Java -11 % 2 = -2, but we need result is 1 like Python.
 * So we add k to the result (It not different if number is positive number).
 * */

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int remainder = 0, result = 0;
        for (int &num:nums) {
            remainder = (remainder + num % k + k) % k;
            result += count[remainder]++;
        }
        return result;
    }
};
