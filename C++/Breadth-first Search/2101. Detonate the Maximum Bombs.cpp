#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        vector<vector<int>> graph(bombs.size());
        for (int i = 0; i < bombs.size(); ++i)
            for (int j = 0; j < bombs.size(); ++j) {
                if (i == j) continue;
                long dx = bombs[i][0] - bombs[j][0], dy = bombs[i][1] - bombs[j][1];
                long dist = dx * dx + dy * dy;
                if (dist <= (long) bombs[i][2] * bombs[i][2])
                    graph[i].push_back(j);
            }
        int result = 0;
        for (int i = 0; i < bombs.size(); ++i) {
            vector<bool> visited(bombs.size());
            queue<int> queue;
            int count = 0;
            visited[i] = true, queue.push(i);
            while (!queue.empty()) {
                count++;
                int u = queue.front();
                queue.pop();
                for (int &v: graph[u])
                    if (!visited[v]) {
                        queue.push(v);
                        visited[v] = true;
                    }
            }
            result = max(result, count);
        }
        return result;
    }

};
