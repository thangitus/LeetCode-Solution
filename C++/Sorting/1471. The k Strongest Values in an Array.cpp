#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), median = arr[(n - 1) / 2], left = 0, right = n - 1;
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            if (median - arr[left] > arr[right] - median)
                result[i] = arr[left++];
            else result[i] = arr[right--];
        }
        return result;
    }
};
