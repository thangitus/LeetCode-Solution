#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/basic-calculator/
 * */

class Solution {
public:
    int calculate(string s) {
        int total = 0;
        vector<int> signs(2, 1);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                long number = 0;
                while (i < s.size() && isdigit(s[i]))
                    number = 10 * number + s[i++] - '0';
                total += signs.back() * number;
                signs.pop_back();
                i--;
            } else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return total;
    }
};

int main() {
    Solution solution;
    solution.calculate("(1+(4+5+2)-3)+(6+8)");
}