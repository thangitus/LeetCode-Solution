#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> queue;
        queue.push(a), queue.push(b), queue.push(c);
        int result = 0;
        while (true) {
            a = queue.top(), queue.pop();
            b = queue.top(), queue.pop();
            if (a > 0 && b > 0) {
                queue.push(a - 1), queue.push(b - 1);
                result++;
            } else break;
        }
        return result;
    }
};
