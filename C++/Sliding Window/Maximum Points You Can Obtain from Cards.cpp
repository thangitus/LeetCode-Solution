#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * */

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int left, minSum, currSum, sum, n = cardPoints.size();
        left = currSum = sum = 0;
        minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];
            if (i < n - k) currSum += cardPoints[i];
        }
        for (int i = n - k; i < n; i++) {
            minSum = min(minSum, currSum);
            currSum -= cardPoints[left++];
            currSum += cardPoints[i];
        }
        minSum = min(minSum, currSum);
        return sum - minSum;
    }
};