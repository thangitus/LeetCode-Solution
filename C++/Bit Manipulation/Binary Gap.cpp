#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/binary-gap/
 * */

class Solution {
public:
    int binaryGap(int n) {
        int result = 0, last = -1;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                if (last >= 0) result = max(result, i - last);
                last = i;
            }
            n >>= 1;
        }
        return result;
    }
};
