#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int> &nums) {
        unordered_set<int> set;
        for (int num: nums) {
            int c = 2;
            while (num > 1) {
                if (num % c == 0) set.insert(c), num /= c;
                else c++;
            }
        }
        return set.size();
    }
};
