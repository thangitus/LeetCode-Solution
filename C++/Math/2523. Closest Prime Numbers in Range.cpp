#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        vector<int> prime, res{-1, -1};
        for (int i = 2; i <= right; ++i) {
            if (!sieve[i]) continue;
            prime.push_back(i);
            int k = i + i;
            while (k <= right) sieve[k] = false, k += i;
        }
        int start = lower_bound(prime.begin(), prime.end(), left) - prime.begin(), minDis = INT_MAX;
        for (int i = start + 1; i < prime.size(); i++) {
            int dis = prime[i] - prime[i - 1];
            if (dis < minDis) {
                minDis = dis;
                res[0] = prime[i - 1], res[1] = prime[i];
            }
        }
        return res;
    }
};
