#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/reordered-power-of-2/
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        sort(s.begin(), s.end());
        for (int i = 0; i < 32; i++) {
            string num = to_string(1 << i);
            sort(num.begin(), num.end());
            if (s == num)
                return true;
        }
        return false;
    }
};
