#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int> &edges) {
        long long maxScore = 0;
        vector<long long> score(edges.size());
        for (int i = 0; i < edges.size(); ++i) {
            score[edges[i]] += i;
            maxScore = max(maxScore, score[edges[i]]);
        }
        for (int i = 0; i < edges.size(); ++i)
            if (score[i] == maxScore) return i;

        return -1;
    }
};
