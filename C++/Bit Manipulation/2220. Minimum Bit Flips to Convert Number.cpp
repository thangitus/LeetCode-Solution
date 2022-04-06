#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0;
        while (start || goal) {
            result += ((start & 1) ^ (goal & 1));
            start >>= 1, goal >>= 1;
        }
        return result;
    }
};
