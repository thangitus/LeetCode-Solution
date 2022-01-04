#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigits(int n) {
        if (n == 0) return 0;
        return 1 + countDigits(n >> 1);
    }

    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        return (1 << countDigits(N)) - 1 - N;
    }
};
