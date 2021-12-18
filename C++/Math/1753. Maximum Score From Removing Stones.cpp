#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        return min(sum / 2, sum - max({a, b, c}));
    }
};
