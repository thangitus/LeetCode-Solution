#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        string res;
        for (char &ch: s) {
            if (stack.empty() || stack.top().first != ch)
                stack.push({ch, 1});
            else {
                auto top = stack.top();
                stack.pop();
                stack.push({ch, top.second + 1});
            }
            if (stack.top().second == k) stack.pop();
        }
        while (!stack.empty()) {
            auto top = stack.top();
            while (top.second--) res += top.first;
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
