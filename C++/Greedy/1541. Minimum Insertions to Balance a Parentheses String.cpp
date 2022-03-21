#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int result = 0, balance = 0;
        for (char &c: s) {
            if (c == '(') {
                if (balance % 2)
                    balance--, result++;
                balance += 2;
            } else {
                balance--;
                if (balance < 0)
                    balance += 2, result++;
            }
        }
        return balance + result;
    }
};
