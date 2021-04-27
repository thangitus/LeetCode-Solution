#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/furthest-building-you-can-reach/
 * */

class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        int len = heights.size() - 1;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < len; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                if (minHeap.size() < ladders) minHeap.push(diff);
                else {
                    if (!minHeap.empty() && diff > minHeap.top()) {
                        int top = minHeap.top();
                        minHeap.pop();
                        minHeap.push(diff);
                        diff = top;
                    }
                    bricks -= diff;
                    if (bricks < 0) return i;
                }
            }
        }
        return len;
    }
};