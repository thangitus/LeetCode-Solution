#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"


using namespace std;

class MyCircularQueue {
private:
    int nums[2000], head, tail, maxSize, curSize;
public:
    MyCircularQueue(int k) {
        head = 1000, tail = 1001, maxSize = k, curSize = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        nums[tail++] = value;
        curSize++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head++, curSize--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return nums[head + 1];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return nums[tail - 1];
    }

    bool isEmpty() {
        return curSize <= 0;
    }

    bool isFull() {
        return curSize >= maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */