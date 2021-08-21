#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * */

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for (char ch:s) {
            string top;
            if (ch == '(')st.push("(");
            else if (ch == ')') {
                while (!st.empty() && st.top() != "(") {
                    top = st.top().append(top);
                    st.pop();
                }
                st.pop();
                reverse(top.begin(), top.end());
                st.push(top);
            } else {
                if (!st.empty() && st.top() != "(") {
                    top = st.top();
                    st.pop();
                }
                top += ch;
                st.push(top);
            }
        }
        string top;
        while (!st.empty()) {
            top = st.top().append(top);
            st.pop();
        }
        return top;
    }
};
