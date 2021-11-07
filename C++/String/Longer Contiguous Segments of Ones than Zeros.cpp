#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
 * */

class Solution {
public:
    bool checkZeroOnes(string s) {
        int count[]{0, 0}, cur[]{0, 0};
        for (char c:s) {
            int i = c == '1';
            cur[i]++, cur[1 - i] = 0;
            count[i] = max(count[i], cur[i]);
            count[1 - i] = max(count[1 - i], cur[1 - i]);
        }
        return count[1] > count[0];
    }
};
