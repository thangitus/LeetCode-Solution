#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int> &nums) {
        unordered_set<int> seen;
        for (int num: nums) {
            seen.insert(num);
            string s = to_string(num);
            std::reverse(s.begin(), s.end());
            seen.insert(stoi(s));
        }
        return seen.size();
    }
};