#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/valid-parentheses/
 * */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &chr : s) {
            if (chr == '(' || chr == '[' || chr == '{') {
                st.push(chr);
                continue;
            }
            if (st.empty()) return false;
            char top = st.top();
            if (chr == ')' && top != '(') return false;
            if (chr == ']' && top != '[') return false;
            if (chr == '}' && top != '{') return false;
            st.pop();
        }
        return st.empty();
    }
};
