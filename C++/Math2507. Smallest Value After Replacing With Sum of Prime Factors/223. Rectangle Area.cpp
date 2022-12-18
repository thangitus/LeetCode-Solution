#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int sum = sumPrimeFactor(n);
            if (sum == n) return n;
            n = sum;
        }
    }

    int sumPrimeFactor(int n) {
        int p = 2, sum = 0;
        while (n > 1) {
            if (n % p == 0) sum += p, n /= p;
            else ++p;
        }
        return sum;
    }
};