#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/fibonacci-number/
 * */

class Solution {
public:
    int fib(int N) {
        int a = 0, b = 1, c;
        if (N == 0) return a;
        if (N == 1) return b;
        while (N-- >= 2) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
