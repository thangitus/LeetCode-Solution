#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int count = 0, cur = num;
        while (cur) {
            count += num % (cur % 10) == 0;
            cur /= 10;
        }
        return count;
    }
};
