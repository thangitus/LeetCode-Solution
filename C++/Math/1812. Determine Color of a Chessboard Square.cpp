#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row = coordinates[0] - 'a' + 1;
        int col = coordinates[1] - '0';
        if (row % 2 && col % 2 == 0) return true;
        if (row % 2 == 0 && col % 2) return true;
        return false;
    }
};
