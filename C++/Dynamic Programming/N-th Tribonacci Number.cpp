#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/n-th-tribonacci-number/
 * */

class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        if (n == 0) return a;
        if (n <= 2) return b;
        while (n > 2) {
            int tmp = c;
            c += a + b;
            a = b;
            b = tmp;
            n--;
        }
        return c;
    }
};