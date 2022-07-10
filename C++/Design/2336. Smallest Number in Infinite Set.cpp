#include <bits/stdc++.h>


using namespace std;

class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<>> heap;
    int cur = 1;
public:
    SmallestInfiniteSet() = default;

    int popSmallest() {
        if (!heap.empty() && heap.top() < cur) {
            int res = heap.top();
            while (!heap.empty() && heap.top() == res)
                heap.pop();
            return res;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur) heap.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */