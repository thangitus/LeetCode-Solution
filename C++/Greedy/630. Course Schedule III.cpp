#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), compare);
        priority_queue<int> maxHeap;
        int time = 0;
        for (auto &course: courses) {
            time += course[0];
            maxHeap.push(course[0]);
            if (time > course[1]) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};
