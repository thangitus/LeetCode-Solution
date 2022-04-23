#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        priority_queue<double> maxHeap(nums.begin(), nums.end());
        int res = 0;
        double sum = 0, curSum;
        for (int &num: nums) sum += num;
        curSum = sum;
        while (curSum >= sum / 2) {
            auto top = maxHeap.top();
            maxHeap.pop();
            top /= 2;
            maxHeap.push(top);
            curSum -= top, res++;
        }
        return res;
    }
};