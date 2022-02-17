#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int> &plants, int capacity) {
        int result = 0, cur = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (cur < plants[i])
                result += i * 2, cur = capacity;
            cur -= plants[i];
            result += 1;
        }
        return result;
    }
};
