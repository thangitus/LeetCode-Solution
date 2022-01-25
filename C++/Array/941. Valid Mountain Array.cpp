#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &arr) {
        if (arr.size() < 3 || arr[0] > arr[1])
            return false;
        bool peak = false;
        for (int i = 1; i < arr.size(); ++i) {
            if ((peak && arr[i - 1] < arr[i]) || arr[i - 1] == arr[i])
                return false;
            peak = arr[i - 1] > arr[i];
        }
        return peak;
    }
};