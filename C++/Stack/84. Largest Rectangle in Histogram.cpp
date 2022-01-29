#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        int n = heights.size(), result = 0;
        stack<int> stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && heights[stack.top()] > heights[i]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - (stack.empty() ? 0 : stack.top() + 1);
                result = max(result, width * height);
            }
            stack.push(i);
        }
        return result;
    }
};
