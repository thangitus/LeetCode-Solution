#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/remove-stones-to-minimize-the-total
 * */

class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> maxHeap;
        for (int i:piles) maxHeap.push(i);
        while (k--) {
            int top = maxHeap.top();
            maxHeap.pop();
            top -= top / 2;
            maxHeap.push(top);
        }
        int sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};
