#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b, char aa = 'a', char bb = 'b', string res = "") {
        if (b > a) return strWithout3a3b(b, a, bb, aa);
        while (a-- > 0) {
            res += aa;
            if (a > b) res += aa, a--;
            if (b-- > 0) res += bb;
        }
        return res;
    }
};
