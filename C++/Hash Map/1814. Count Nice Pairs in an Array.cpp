#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNicePairs(vector<int> &nums) {
        unordered_map<int, int> count;
        long long result = 0, mod = 1e9 + 7;
        for (int &num: nums) {
            string str = to_string(num);
            reverse(str.begin(), str.end());
            int rev = stoi(str);
            result += count[num - rev];
            result %= mod;
            count[num - rev]++;
        }
        return (int) result;
    }
};
