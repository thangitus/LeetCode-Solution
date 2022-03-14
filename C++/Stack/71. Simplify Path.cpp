#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        string result;
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == '/') continue;
            string temp;
            while (i < path.size() && path[i] != '/')
                temp += path[i++];
            if (temp == ".") continue;
            else if (temp == "..") {
                if (!stack.empty())
                    stack.pop();
            } else stack.push(temp);
        }
        while (!stack.empty()) {
            result = "/" + stack.top() + result;
            stack.pop();
        }
        if (result.length() == 0) return "/";
        return result;
    }
};
