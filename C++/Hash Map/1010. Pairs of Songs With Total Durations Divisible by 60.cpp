#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int count[60]{}, result = 0;
        for (int i: time)
            count[i % 60]++;
        for (int i = 0; i <= 30; i++) {
            if (i != 30 && i != 0) {
                result += count[i] * count[60 - i];
            } else if (count[i] > 1) {
                int n = count[i] - 1;
                result += (1 + n) * n / 2;
            }
        }
        return result;
    }
};
