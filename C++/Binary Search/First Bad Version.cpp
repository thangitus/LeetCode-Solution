#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-peak-element/
 * */

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int result = n;
        long long left = 1, right = n;
        while (left <= right) {
            auto mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                result = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return result;
    }
};