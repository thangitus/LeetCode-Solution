#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int nums[n + 1];
        priority_queue<pair<long, pair<long, long>>, vector<pair<long, pair<long, long>>>, greater<>> heap;
        for (int prime: primes)
            heap.push({prime, {prime, 0}});
        int i = 2;
        nums[1] = 1;
        while (i <= n) {
            auto top = heap.top();
            heap.pop();
            long num = top.first, prime = top.second.first, index = top.second.second + 1;
            if (num != nums[i - 1])
                nums[i++] = num;
            heap.push({prime * nums[index], {prime, index}});
        }
        return nums[n];
    }
};
