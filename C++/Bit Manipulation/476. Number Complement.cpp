#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long tmp = num, max = 1;
        while (tmp) {
            max <<= 1;
            tmp >>= 1;
        }
        return max - num - 1;
    }
};
