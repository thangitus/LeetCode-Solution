#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; ++i) {
            int left = i * (i - 1) / 2;
            int right = (n - i + 1) * (i + n) / 2;
            if (left == right) return i;
        }
        return -1;
    }
};