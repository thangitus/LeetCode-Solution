#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        for (int i = 0; i < equations.size(); ++i) {
            auto a = equations[i][0], b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1 / values[i];
        }
        vector<double> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto a = queries[i][0], b = queries[i][1];
            unordered_set<string> visited;
            visited.insert(a);
            result[i] = dfs(a, b, 1, visited);
        }
        return result;
    }

    double dfs(const string &cur, string &des, double res, unordered_set<string> &visited) {
        if (graph.find(cur) == graph.end() || graph.find(des) == graph.end()) return -1;
        if (cur == des) return res;
        for (auto &item: graph[cur]) {
            if (visited.count(item.first)) continue;
            visited.insert(item.first);
            auto result = dfs(item.first, des, res * item.second, visited);
            if (result >= 0) return result;
        }
        return -1;
    }
};
