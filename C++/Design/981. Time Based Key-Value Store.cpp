#include <bits/stdc++.h>


using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string>> map;
public:

    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = map[key].upper_bound(timestamp);
        return it == map[key].begin() ? "" : prev(it)->second;
    }
};
