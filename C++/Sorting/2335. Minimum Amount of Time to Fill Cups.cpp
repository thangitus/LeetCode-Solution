#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fillCups(vector<int> &amount) {
        sort(amount.begin(), amount.end(), greater<>());
        if (!amount[0]) return 0;
        if (amount[1]) {
            amount[0]--, amount[1]--;
            return 1 + fillCups(amount);
        } else return amount[0];
    }
};
