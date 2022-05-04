#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        while (a || b || c) {
            int bitA = a & 1, bitB = b & 1, bitC = c & 1;
            if (bitC) result += (1 - (bitA | bitB));
            else result += 2 - !bitA - !bitB;
            a >>= 1, b >>= 1, c >>= 1;
        }
        return result;
    }
};
