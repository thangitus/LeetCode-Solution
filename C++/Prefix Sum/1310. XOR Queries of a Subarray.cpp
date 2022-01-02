#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> prefix(nums.size()), result(queries.size());
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i)
            prefix[i] = cur ^= nums[i];
        for (int i = 0; i < queries.size(); ++i) {
            int prev = queries[i][0] != 0 ? prefix[queries[i][0] - 1] : 0;
            result[i] = prefix[queries[i][1]] ^ prev;
        }
        return result;
    }
};
