#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stack;
        int j = 0;
        for (int & num : pushed) {
            stack.push(num);
            while (!stack.empty() && popped[j] == stack.top())
                j++, stack.pop();
        }
        return j == popped.size();
    }
};
