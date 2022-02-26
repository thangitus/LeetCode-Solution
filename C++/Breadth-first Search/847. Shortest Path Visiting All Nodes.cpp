#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size(), endMask = (1 << n) - 1, step = 0;
        if (n <= 1) return 0;
        vector<vector<bool>> seen(n, vector<bool>(endMask));
        queue<pair<int, int>> queue;
        for (int i = 0; i < n; ++i) {
            queue.push({i, 1 << i});
            seen[i][1 << i] = true;
        }
        while (!queue.empty()) {
            step++;
            for (int k = queue.size(); k > 0; --k) {
                auto cur = queue.front();
                queue.pop();
                int node = cur.first, mask = cur.second;
                for (int neighbor: graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    if (nextMask == endMask) return step;
                    if (!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        queue.push({neighbor, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};
