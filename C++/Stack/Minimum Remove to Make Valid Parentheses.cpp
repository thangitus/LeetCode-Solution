#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> flags(s.length());
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]))
                flags[i] = true;
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')' && !st.empty()) {
                flags[i] = true;
                flags[st.top()] = true;
                st.pop();
            }
        }
        string result;
        for (int i = 0; i < s.length(); i++)
            if (flags[i])
                result += s[i];
        return result;
    }
};
