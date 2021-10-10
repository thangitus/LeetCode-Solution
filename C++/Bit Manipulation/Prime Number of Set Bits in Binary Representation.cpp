#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 * */

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        const unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int result = 0;
        for (int i = left; i <= right; i++) {
            int countBitOne = 0, num = i;
            while (num) {
                countBitOne += num & 1;
                num >>= 1;
            }
            result += primes.count(countBitOne);
        }
        return result;
    }
};
