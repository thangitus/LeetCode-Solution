#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> closePos;

    string decodeString(string s) {
        stack<int> stack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '[') stack.push(i);
            else if (s[i] == ']') {
                closePos[stack.top()] = i;
                stack.pop();
            }
        }
        return solve(s, 0, s.length());
    }

    string solve(string &s, int left, int right) {
        string result;
        int num = 0;
        while (left < right) {
            char c = s[left];
            if (isdigit(c)) num = num * 10 + c - '0';
            else if (c == '[') {
                string sub = solve(s, left + 1, closePos[left]);
                for (int i = 0; i < num; i++)
                    result += sub;
                left = closePos[left];
                num = 0;
            } else result += c;
            left++;
        }
        return result;
    }
};
