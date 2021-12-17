#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int> &arr) {
        int steps = 0, n = arr.size();
        unordered_map<int, vector<int>> map;
        vector<bool> visited(n);
        queue<int> queue;
        queue.push(0);
        for (int i = 0; i < n; i++)
            map[arr[i]].push_back(i);
        while (!queue.empty()) {
            for (int k = queue.size(); k > 0; k--) {
                int u = queue.front();
                queue.pop();
                if (u == n - 1) return steps;
                visited[u] = true;
                if (u > 0 && !visited[u - 1])
                    queue.push(u - 1);
                if (u < n - 1 && !visited[u + 1])
                    queue.push(u + 1);
                for (int pos: map[arr[u]])
                    if (!visited[pos]) queue.push(pos);
                map[arr[u]].clear();
            }
            steps++;
        }
        return steps;
    }
};
