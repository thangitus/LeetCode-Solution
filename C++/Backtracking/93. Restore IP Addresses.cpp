#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> result;

    vector<string> restoreIpAddresses(string s) {
        string cur;
        backtracking(s, cur, 0, 0);
        return result;
    }

    void backtracking(string &s, string &cur, int start, int count) {
        if (count == 4 && start == s.length())
            result.push_back(cur);
        string num;
        for (int i = start; i < start + 3 && i < s.length(); i++) {
            num += s[i];
            if (num.length() > 1 && num[0] == '0') break;
            if (stoi(num) <= 255) {
                int curLength = cur.length();
                cur += num;
                if (count < 3) cur += '.';
                backtracking(s, cur, i + 1, count + 1);
                while (cur.length() != curLength) cur.pop_back();
            }
        }
    }
};
