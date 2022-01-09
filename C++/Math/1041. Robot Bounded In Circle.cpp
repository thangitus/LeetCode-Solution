#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, degree = 90;
        for (char &c: instructions) {
            if (c == 'G') {
                y += degree == 90;
                y -= degree == 270;
                x -= degree == 0;
                x += degree == 180;
            } else if (c == 'L') degree += 90;
            else degree -= 90;
            degree = (degree + 360) % 360;
        }
        if (x == 0 && y == 0) return true;
        return degree != 90;
    }
};
