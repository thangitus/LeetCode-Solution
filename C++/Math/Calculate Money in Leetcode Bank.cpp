#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/calculate-money-in-leetcode-bank/
 * */

class Solution {
public:
    int totalMoney(int n) {
        int w1 = (1 + 7) * 7 / 2; // After 1 week we get the amount of w1
        int week = n / 7, ans = week * (2 * w1 + (week - 1) * 7) / 2; // Total amount we get affer n/7 week
        n %= 7;
        int u1 = 1 + week, un = u1 + n - 1;
        return ans + (u1 + un) * n / 2;
    }
};