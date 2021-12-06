#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {
        int count[]{0, 0};
        for (int p: position)
            count[p % 2]++;
        return min(count[0], count[1]);
    }
};
