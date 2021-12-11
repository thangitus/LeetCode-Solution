#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums)
            count[((num % k) + k) % k]++;
        if (count[0] % 2) return false;
        for (int i = 1; i <= k / 2; i++)
            if (count[i] != count[k - i])
                return false;
        return true;
    }
};
