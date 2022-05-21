#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int memo[100000];

    int getKth(int lo, int hi, int k) {
        fill_n(memo, 100000, -1);
        memo[1] = 0;
        vector<pair<int, int>> nums;
        for (int i = lo; i <= hi; ++i)
            nums.emplace_back(dfs(i), i);
        sort(nums.begin(), nums.end());
        return nums[k - 1].second;
    }

    int dfs(int cur) {
        if (memo[cur] == -1) {
            memo[cur] = (cur & 1) ? dfs(cur * 3 + 1) :
                        dfs(cur / 2);
            memo[cur]++;
        }
        return memo[cur];
    }
};
