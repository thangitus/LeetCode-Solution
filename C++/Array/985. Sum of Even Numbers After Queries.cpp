#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> result;
        int sum = 0;
        for (int &num: nums)
            sum += (num & 1) == 0 ? num : 0;
        for (auto &query: queries) {
            int &num = nums[query[1]];
            if (!(num & 1))
                sum -= num;
            num += query[0];
            if (!(num & 1)) sum += num;
            result.push_back(sum);
        }
        return result;
    }
};
