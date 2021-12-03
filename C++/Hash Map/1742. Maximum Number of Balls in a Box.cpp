#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(46);
        int result = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, num = i;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            result = max(result, ++count[sum]);
        }
        return result;
    }
};
