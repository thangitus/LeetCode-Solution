#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/all-paths-from-source-to-target/
 */

class Solution {
public:

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(graph, result, cur, 0);
        return result;
    }

    void dfs(vector<vector<int>> &graph, vector<vector<int>> &result, vector<int> &curr, int currNode) {
        curr.push_back(currNode);
        if (currNode == graph.size() - 1) result.push_back(curr);
        else
            for (int node: graph[currNode])
                dfs(graph, result, curr, node);
        curr.pop_back();
    }
};