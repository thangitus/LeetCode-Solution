#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        long long sum = 0, cur = 0;
        for (auto &customer: customers) {
            cur = max((long long) customer[0], cur) + customer[1];
            sum += cur - customer[0];
        }
        return sum * 1.0 / customers.size();
    }
};
