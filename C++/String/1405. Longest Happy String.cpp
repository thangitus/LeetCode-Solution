#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b) return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c) return longestDiverseString(a, c, b, aa, cc, bb);
        if (b == 0) return string(min(a, 2), aa);
        int useA = min(a, 2), useB = a - useA >= b ? 1 : 0;
        return string(useA, aa) + string(useB, bb)
               + longestDiverseString(a - useA, b - useB, c, aa, bb, cc);
    }
};
