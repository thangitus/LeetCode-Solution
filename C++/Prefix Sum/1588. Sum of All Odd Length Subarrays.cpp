#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int result = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            int contribution = ceil((i + 1) * (n - i) / 2.0);
            result += (contribution * arr[i]);
        }
        return result;
    }
};
