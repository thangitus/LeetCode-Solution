#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/add-minimum-number-of-rungs/
 * */

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0;
        for (int &bill:bills) {
            if (bill == 5) five++;
            else if (bill == 10) five--, ten++;
            else if (ten > 0) ten--, five--;
            else five -= 3;
            if (five < 0) return false;
        }
        return true;
    }
};
