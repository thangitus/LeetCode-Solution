#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/min-stack/
 * */

class MinStack {
private:
    stack<pair<int, int>> stack;
public:
    MinStack() {

    }

    void push(int val) {
        int minVal = val;
        if (!stack.empty()) minVal = min(minVal, stack.top().second);
        stack.push({val, minVal});
    }

    void pop() {
        stack.pop();
    }

    int top() {
        return stack.top().first;
    }

    int getMin() {
        return stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
