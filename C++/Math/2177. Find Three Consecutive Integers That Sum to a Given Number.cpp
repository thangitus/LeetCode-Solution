#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        auto sum = num - 3;
        if (sum % 3) return {};
        return {sum / 3, sum / 3 + 1, sum / 3 + 2};
    }
};
