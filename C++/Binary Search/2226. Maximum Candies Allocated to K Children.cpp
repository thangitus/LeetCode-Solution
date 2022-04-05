#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int> &candies, long long k) {
        int low = 0, high = 1e7;
        while (low < high) {
            int mid = (high + low + 1) / 2;
            if (isValid(candies, k, mid))
                low = mid;
            else high = mid - 1;
        }
        return low;
    }

    bool isValid(vector<int> &candies, long long k, int mid) {
        if (mid == 0) return true;
        long long count = 0;
        for (int &candy: candies)
            count += candy / mid;
        return count >= k;
    }
};
