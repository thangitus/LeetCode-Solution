#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int left = 0, right = max(houses.back(), heaters.back()), result;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(houses, heaters, mid)) {
                result = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return result;
    }

    bool isValid(vector<int> &houses, vector<int> &heaters, int radius) {
        long left = heaters[0] - radius, right = heaters[0] + radius, i = 0, j = 0;
        if (houses[0] < left) return false;
        while (i < houses.size() && j < heaters.size()) {
            if (left <= houses[i] && houses[i] <= right) i++;
            else {
                if (j == heaters.size() - 1) return false;
                j++;
                left = heaters[j] - radius;
                right = heaters[j] + radius;
            }
        }
        return i == houses.size();
    }
};
