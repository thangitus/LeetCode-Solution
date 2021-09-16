#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/majority-element/
 * */

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0, result;
        for (int &num : nums) {
            if (count == 0) result = num;
            count += (num == result) ? 1 : -1;
        }
        return result;
    }
};
