#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2) {
        int start1 = time(event1[0]), end1 = time(event1[1]);
        int start2 = time(event2[0]), end2 = time(event2[1]);
        if (start1 > start2) {
            swap(start1, start2);
            swap(end1, end2);
        }
        return start2 <= end1;
    }

    int time(string &s) {
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3));
        return h * 60 + m;
    }
};