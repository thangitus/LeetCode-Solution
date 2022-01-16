#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int result = 0;
        while (target != 1) {
            if (maxDoubles == 0) {
                result += (target - 1);
                break;
            }
            if (target % 2 == 0)
                target /= 2, maxDoubles--;
            else target--;
            result++;
        }
        return result;
    }
};
