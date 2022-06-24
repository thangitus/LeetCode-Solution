#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &target) {
        if (target.size() == 1) return target[0] == 1;
        long long sum = accumulate(target.begin(), target.end(), 0LL);
        priority_queue<long long> maxHeap(target.begin(), target.end());
        while (maxHeap.top() != 1) {
            auto top = maxHeap.top();
            if (sum - top == 1) return true;
            auto x = top % (sum - top);
            sum = sum - top + x;
            maxHeap.pop();
            if (x == 0 || x == top) return false;
            maxHeap.push(x);

        }
        return true;
    }
};
