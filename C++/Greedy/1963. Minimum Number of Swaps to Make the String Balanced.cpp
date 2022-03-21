#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int result = 0, balance = 0;
        for (char c: s) {
            balance += c == '[' ? 1 : -1;
            if (balance < 0)
                result++, balance = 1; //swap
        }
        return result;
    }
};
