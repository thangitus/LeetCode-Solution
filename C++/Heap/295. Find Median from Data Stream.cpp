#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    priority_queue<long, vector<long>, greater<>> large;
    priority_queue<long> small;
public:
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size() ? small.top() :
               double(small.top() + large.top()) / 2;
    }
};
