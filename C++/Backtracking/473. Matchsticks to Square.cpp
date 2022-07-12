#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int avg;

    bool makesquare(vector<int> &matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        vector<int> sums(4);
        if (sum % 4) return false;
        avg = sum / 4;
        return backtracking(matchsticks, 0, sums);
    }

    bool backtracking(vector<int> &matchsticks, int i, vector<int> &sums) {
        if (i == matchsticks.size())
            return !(sums[0] ^ sums[1] ^ sums[2] ^ sums[3]);
        for (int j = 0; j < 4; ++j) {
            bool duplicated = false;
            for (int k = 0; k < j && !duplicated; ++k)
                duplicated = sums[k] == sums[j];
            if (duplicated) continue;
            sums[j] += matchsticks[i];
            if (sums[j] <= avg && backtracking(matchsticks, i + 1, sums))
                return true;
            sums[j] -= matchsticks[i];
        }
        return false;
    }
};