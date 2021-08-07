#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
 * */

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibonacci{1, 1};
        while (fibonacci.back() < k) {
            auto n = fibonacci.size();
            fibonacci.push_back(fibonacci[n - 1] + fibonacci[n - 2]);
        }
        int res = 0;
        while (k) {
            if (k >= fibonacci.back()) {
                k -= fibonacci.back();
                res++;
            } else fibonacci.pop_back();
        }
        return res;
    }
};