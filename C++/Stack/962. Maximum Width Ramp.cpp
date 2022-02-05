#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int> &nums) {
        stack<int> stack;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (stack.empty() || nums[stack.top()] > nums[i])
                stack.push(i);
        for (int i = nums.size() - 1; i >= 0; --i)
            while (!stack.empty() && nums[stack.top()] <= nums[i])
                result = max(result, i - stack.top()), stack.pop();
        return result;
    }
};