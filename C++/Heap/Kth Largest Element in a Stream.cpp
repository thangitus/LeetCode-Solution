#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * */

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    void insertHeap(int &i) {
        if (minHeap.size() < k)
            minHeap.push(i);
        else {
            int top = minHeap.top();
            if (top < i) {
                minHeap.pop();
                minHeap.push(i);
            }
        }
    }

public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int &i:nums)
            insertHeap(i);
    }

    int add(int val) {
        insertHeap(val);
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */