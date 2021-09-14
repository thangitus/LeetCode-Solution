#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/time-needed-to-inform-all-employees/
 * */

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                graph[manager[i]].push_back(i);
        return dfs(graph, informTime, headID);
    }

    int dfs(vector<vector<int>> &graph, vector<int> &informTime, int employee) {
        int result = 0;
        for (int &val: graph[employee])
            result = max(result, dfs(graph, informTime, val));
        return result + informTime[employee];
    }
};
