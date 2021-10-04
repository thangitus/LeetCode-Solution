#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 * */

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        vector<int> count(n), result;
        for (auto &edge:edges)
            count[edge[1]]++;
        for (int i = 0; i < n; i++)
            if (!count[i]) result.push_back(i);
        return result;
    }
};
