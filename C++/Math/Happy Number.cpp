#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/happy-number/
 * */

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mSet;
        while (true) {
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
            if (n == 1) return true;
            if (mSet.count(n)) return false;
            mSet.insert(n);
        }
    }
};
