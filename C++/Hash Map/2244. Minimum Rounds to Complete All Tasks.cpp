#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> count;
        int res = 0;
        for (int &task: tasks) ++count[task];
        for (auto &it: count) {
            if (it.second == 1) return -1;
            res += (it.second + 2) / 3;
        }
        return res;
    }
};
