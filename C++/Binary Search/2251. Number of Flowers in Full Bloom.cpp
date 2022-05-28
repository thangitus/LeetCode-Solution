#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        int init = 0, n = persons.size();
        vector<int> res(n);
        map<int, int> change, count;
        for (auto &flower: flowers)
            change[flower[0]]++, change[flower[1] + 1]--;
        for (auto &item: change)
            count[item.first] = init += item.second;
        for (int i = 0; i < n; ++i) {
            int time = persons[i];
            auto it = count.lower_bound(time);
            if (it->first > time)
                res[i] = it == count.begin() ? 0 : prev(it)->second;
            else res[i] = it->second;
        }
        return res;
    }
};

