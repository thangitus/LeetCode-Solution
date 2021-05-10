#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/calculate-money-in-leetcode-bank/
 * */

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrimes(n, true);
        for (int i = 2; i * i < n; i++) {
            if (!isPrimes[i]) continue;
            for (int j = i * i; j < n; j += i) isPrimes[j] = false;
        }
        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrimes[i]) count++;
        return count;
    }
};