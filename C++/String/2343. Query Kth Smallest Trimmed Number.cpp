#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        int m = nums.size();
        vector<int> res;
        for (auto &query: queries) {
            int trim = query[1], k = query[0] - 1;
            vector<pair<string, int>> str(m);
            for (int i = 0; i < m; ++i) {
                int startIndex = nums[i].length() - trim;
                str[i] = {nums[i].substr(startIndex), i};
            }
            std::sort(str.begin(), str.end());
            res.push_back(str[k].second);
        }
        return res;
    }
};
