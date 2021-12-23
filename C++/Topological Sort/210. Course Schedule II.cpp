#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses), result;
        for (auto &item: prerequisites)
            graph[item[1]].push_back(item[0]);
        for (int u = 0; u < numCourses; u++)
            for (int v: graph[u])
                degree[v]++;
        queue<int> queue;
        for (int u = 0; u < numCourses; u++)
            if (degree[u] == 0) queue.push(u);
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            result.push_back(u);
            for (int v: graph[u])
                if (--degree[v] == 0)
                    queue.push(v);
        }
        if (result.size() < numCourses) result.clear();
        return result;
    }
};
