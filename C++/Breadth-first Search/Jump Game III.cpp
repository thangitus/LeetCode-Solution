#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/jump-game-iii/
 * */

class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<bool> flag(n, false);
        queue<int> queue;
        queue.push(start);
        while (!queue.empty()) {
            int i = queue.front();
            queue.pop();
            if (!arr[i]) return true;
            flag[i] = true;
            int left = i - arr[i];
            int right = i + arr[i];
            if (left >= 0 && !flag[left])
                queue.push(left);
            if (right < n && !flag[right])
                queue.push(right);
        }
        return false;
    }
};