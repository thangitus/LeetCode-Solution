#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        string num = to_string(n);
        int digit = num.size(), result = 0, size = digits.size();
        for (int i = 1; i < digit; i++)
            result += pow(size, i);
        for (int i = 0; i < digit; ++i) {
            bool hasSameNum = false;
            for (string &d: digits) {
                if (d[0] < num[i])
                    result += pow(size, digit - i - 1);
                else if (d[0] == num[i])
                    hasSameNum = true;
            }
            if (!hasSameNum) return result;
        }
        return result + 1;
    }
};
