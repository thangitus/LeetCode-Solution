#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 * */

class Solution {
public:
    int maxEvents(vector<vector<int>> &events) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        sort(events.begin(), events.end());
        int res, day, i, n = events.size();
        res = day = i = 0;
        while (!minHeap.empty() || i < n) {
            if (minHeap.empty())
                day = events[i][0];
            while (i < n && events[i][0] <= day)
                minHeap.push(events[i++][1]);
            minHeap.pop();
            res++, day++;
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();
        }
        return res;
    }
};