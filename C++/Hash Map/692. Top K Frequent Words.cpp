#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(pair<int, string> &a, pair<int, string> &b) {
        if (a.first != b.first)
            return a.first > b.first;
        else
            return a.second < b.second;
    }

    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> count;
        for (auto &word: words)
            count[word]++;
        vector<pair<int, string>> arr;
        arr.reserve(count.size());
        for (auto &item: count)
            arr.emplace_back(item.second, item.first);
        sort(arr.begin(), arr.end(), compare);
        vector<string> result(k);
        for (int i = 0; i < k; ++i)
            result[i] = arr[i].second;
        return result;
    }
};
