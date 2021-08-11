#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
 * */

class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &arr) {
        int sum = 0;
        for (int i:arr) sum += i;
        if (sum % 3) return false;
        int count = 0, avg = sum / 3;
        sum = 0;
        for (int value:arr) {
            sum += value;
            if (sum == avg) {
                count++;
                sum = 0;
            }
        }
        return count >= 3;
    }
};