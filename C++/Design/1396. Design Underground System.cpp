#include <bits/stdc++.h>


using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> customer;
    unordered_map<string, vector<int>> time;
public:
    UndergroundSystem() {}

    void checkIn(int id, string startStation, int t) {
        customer[id] = {startStation, t};
    }

    void checkOut(int id, string endStation, int t) {
        string startStation = customer[id].first;
        int timeStart = customer[id].second;
        auto &travel = time[startStation + '-' + endStation];
        if (travel.empty()) travel.resize(2);
        travel[0] += t - timeStart;
        travel[1]++;
    }

    double getAverageTime(string startStation, string endStation) {
        auto &travel = time[startStation + '-' + endStation];
        return travel[0] * 1.0 / travel[1];
    }
};
