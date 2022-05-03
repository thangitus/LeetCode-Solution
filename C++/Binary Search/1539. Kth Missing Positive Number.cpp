#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            int numberMissing = arr[mid] - 1 - mid;
            if (numberMissing < k)
                left = mid + 1;
            else right = mid;
        }
        return left + k;
    }
};
