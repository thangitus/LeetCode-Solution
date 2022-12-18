#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = ::abs(target);
        int n = 1, sum = 0;
        while (sum < target || (sum - target) % 2)
            sum += n, n++;

        return n - 1;
    }
};
