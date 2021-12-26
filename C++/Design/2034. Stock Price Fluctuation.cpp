#include <bits/stdc++.h>

using namespace std;

class StockPrice {
private:
    unordered_map<int, int> map;
    priority_queue<int, vector<int>, greater<>> minHeap, removedMin;
    priority_queue<int> maxHeap, removedMax;
    int lastTime = 0;
public:
    void update(int timestamp, int price) {
        if (map[timestamp]) {
            removedMin.push(map[timestamp]);
            removedMax.push(map[timestamp]);
        }

        map[timestamp] = price;
        lastTime = max(lastTime, timestamp);
        minHeap.push(price);
        maxHeap.push(price);
    }

    int current() {
        return map[lastTime];
    }

    int maximum() {
        while (!removedMax.empty() && removedMax.top() == maxHeap.top()) {
            removedMax.pop();
            maxHeap.pop();
        }
        return maxHeap.top();
    }

    int minimum() {
        while (!removedMin.empty() && removedMin.top() == minHeap.top()) {
            removedMin.pop();
            minHeap.pop();
        }
        return minHeap.top();
    }
};

