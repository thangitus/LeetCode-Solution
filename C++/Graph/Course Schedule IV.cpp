#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/course-schedule-iv/
 * Floyd warshall algorithm
 * */

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<vector<bool>> connect(n, vector<bool>(n));
        for (int i = 0; i < n; i++) connect[i][i] = true;
        for (auto &prerequisite:prerequisites)
            connect[prerequisite[0]][prerequisite[1]] = true;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    connect[i][j] = connect[i][j] || (connect[i][k] && connect[k][j]);
        vector<bool> result;
        for (auto &q:queries)
            result.push_back(connect[q[0]][q[1]]);
        return result;
    }
};
