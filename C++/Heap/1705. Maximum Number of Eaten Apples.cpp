#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<>> minHeap;
        int result = 0, i = 0;
        while (!minHeap.empty() || i < apples.size()) {
            if (i < apples.size() && apples[i]) {
                minHeap.push(i + days[i]);
                count[i + days[i]] += apples[i];
            }
            while (!minHeap.empty() &&
                   (minHeap.top() < i || count[minHeap.top()] == 0))
                minHeap.pop();
            if (!minHeap.empty()) {
                count[minHeap.top()]--;
                result++;
            }
            i++;
        }
        return result;
    }
};