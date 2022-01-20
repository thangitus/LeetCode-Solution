#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        int maxVal = arr[0], count = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
                count = 0;
            }
            if (++count == k) break;
        }
        return maxVal;
    }
};
