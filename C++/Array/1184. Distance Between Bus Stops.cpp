
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        int sum = accumulate(distance.begin(), distance.end(), 0), result = 0;
        if (start > destination)
            swap(start, destination);
        while (start != destination)
            result += distance[start++];
        return min(result, sum - result);
    }
};
