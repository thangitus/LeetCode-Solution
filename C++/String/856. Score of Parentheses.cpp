#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int result = 0, balance = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') balance++;
            else {
                balance--;
                if (s[i - 1] == '(')
                    result += (1 << balance);
            }
        }
        return result;
    }
};