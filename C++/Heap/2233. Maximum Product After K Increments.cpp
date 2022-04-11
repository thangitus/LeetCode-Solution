#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap(nums.begin(), nums.end());
        while (k--) {
            int top = minHeap.top();
            minHeap.pop();
            minHeap.push(top + 1);
        }
        long long result = 1, mod = 1e9 + 7;
        while (!minHeap.empty()) {
            result = (result * minHeap.top()) % mod;
            minHeap.pop();
        }
        return (int) result;
    }
};
