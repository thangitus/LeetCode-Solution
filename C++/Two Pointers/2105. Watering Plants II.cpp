#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int result = 0, left = 0, right = plants.size() - 1, remain[]{capacityA, capacityB};
        while (left <= right) {
            if (left == right) {
                if (max(remain[0], remain[1]) < plants[left])
                    result++;
                break;
            }
            if (plants[left] > remain[0])
                remain[0] = capacityA, result++;
            if (plants[right] > remain[1])
                remain[1] = capacityB, result++;
            remain[0] -= plants[left++];
            remain[1] -= plants[right--];
        }
        return result;
    }
};
