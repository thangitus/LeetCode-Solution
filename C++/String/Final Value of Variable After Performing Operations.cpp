#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
 * */

class Solution {
public:
    int finalValueAfterOperations(vector<string> &operations) {
        int result = 0;
        for (string &str:operations)
            if (str == "X++" || str == "++X") result++;
            else result--;
        return result;
    }
};