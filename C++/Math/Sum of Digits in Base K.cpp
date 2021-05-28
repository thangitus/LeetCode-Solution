#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/sum-of-digits-in-base-k/
 * */

class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while (n) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
};