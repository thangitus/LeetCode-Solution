#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        int curPos = startFuel, i = 0, res = 0;
        priority_queue<int> queue;
        while (curPos < target) {
            while (i < stations.size() && curPos >= stations[i][0])
                queue.push(stations[i++][1]);
            if (queue.empty()) return -1;
            res++, curPos += queue.top();
            queue.pop();
        }
        return res;
    }
};
