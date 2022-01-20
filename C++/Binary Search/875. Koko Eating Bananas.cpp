#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = (right + left) / 2;
            if (count(piles, mid) <= h)
                right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    int count(vector<int> &piles, int k) {
        int result = 0;
        for (int pile: piles)
            result += ceil(1.0 * pile / k);
        return result;
    }
};
