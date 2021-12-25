#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int ugly[n], idx[primes.size()];
        memset(ugly, 0, sizeof(ugly));
        memset(idx, 0, sizeof(idx));
        ugly[0] = 1;

        for (int i = 1; i < n; ++i) {
            ugly[i] = INT_MAX;
            for (int j = 0; j < primes.size(); ++j)
                ugly[i] = min(ugly[i], primes[j] * ugly[idx[j]]);
            for (int j = 0; j < primes.size(); ++j)
                if (primes[j] * ugly[idx[j]] == ugly[i]) idx[j]++;
        }
        return ugly[n - 1];
    }
};