#include <bits/stdc++.h>

using namespace std;
/*
 * Link: https://leetcode.com/problems/climbing-stairs/
 * Tại bậc x thì có thể chọn đi lên bậc x+1 hoặc x+2
 * Gọi f(x) là số cách đi của bậc thứ x thì: f(x)=f(x-1) + f(x-2)
 * */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int a = 1, b = 2, c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};