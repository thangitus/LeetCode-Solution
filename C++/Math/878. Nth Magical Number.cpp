#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / __gcd(A, B), l = 2, r = 1e14, mod = 1e9 + 7;
        while (l < r) {
            long m = (l + r) / 2;
            if (m / A + m / B - m / lcm < N) l = m + 1;
            else r = m;
        }
        return l % mod;
    }
};