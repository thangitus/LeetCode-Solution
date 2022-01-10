#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
        vector<pair<int, int>> vector(plantTime.size());
        for (int i = 0; i < plantTime.size(); ++i)
            vector[i] = {growTime[i], plantTime[i]};
        sort(vector.begin(), vector.end(), greater<>());
        int curDay = 0, result = 0;
        for (auto &item: vector) {
            curDay += item.second;
            result = max(result, curDay + item.first);
        }
        return result;
    }
};
