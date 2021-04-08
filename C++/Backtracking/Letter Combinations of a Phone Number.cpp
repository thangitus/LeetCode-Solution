#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        string s = "";
        backstracking(digits, s, ans);
        return ans;
    }

    void backstracking(string &digits, string &s, vector<string> &ans) {
        int length = s.length();
        if (length == digits.length()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[length] - '0' - 2;
        char c = digit * 3 + 'a';
        int loop = digit != 5 && digit != 7 ? 3 : 4;
        c += digit > 5 ? 1 : 0;
        s += ' ';
        for (char i = c; i < c + loop; i++) {
            s[length] = i;
            backstracking(digits, s, ans);
        }
        s.erase(s.length() - 1, 1);
    }
};

int main() {
    Solution solution;
    solution.letterCombinations("78");
    return 0;
}