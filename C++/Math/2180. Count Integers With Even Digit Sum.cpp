#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countEven(int num) {
        int result = 0;
        for (int i = 1; i <= num; ++i) {
            int n = i, sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            result += (sum % 2 == 0);
        }
        return result;
    }
};