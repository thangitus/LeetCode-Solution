#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views) {
        unordered_map<string, pair<long, unordered_map<string, long>>> count;
        vector<vector<string>> res;
        long maxPopular = 0;
        for (int i = 0; i < creators.size(); ++i) {
            auto creator = creators[i], id = ids[i];
            long view = views[i];
            auto &item = count[creator];
            item.second[id] = max(view, item.second[id]);
            item.first += view;
            maxPopular = max(maxPopular, item.first);
        }
        for (auto &item: count)
            if (item.second.first == maxPopular) {
                long maxView = 0;
                string id, creator = item.first;
                for (auto &video: item.second.second) {
                    if (id.empty() || video.second > maxView) id = video.first, maxView = video.second;
                    else if (video.second == maxView)id = min(video.first, id);
                }
                res.push_back({creator, id});
            }
        return res;
    }
};


