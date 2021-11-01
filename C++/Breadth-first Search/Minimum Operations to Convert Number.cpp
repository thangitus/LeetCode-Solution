#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-operations-to-convert-number/
 * */

class Solution {
public:
    int minimumOperations(vector<int> &nums, int start, int goal) {
        int step = 0;
        vector<bool> visited(1001);
        queue<int> queue;
        queue.push(start);
        while (!queue.empty()) {
            int size = queue.size();
            while (size--) {
                int cur = queue.front();
                queue.pop();
                if (cur == goal)return step;
                if (cur > 1000 || cur < 0 || visited[cur]) continue;
                visited[cur] = true;
                for (int num : nums) {
                    queue.push(cur + num);
                    queue.push(cur - num);
                    queue.push(cur ^ num);
                }
            }
            step++;
        }
        return -1;
    }
};
