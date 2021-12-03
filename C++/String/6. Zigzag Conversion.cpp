#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> grid(numRows);
        int i = 0, len = s.length();
        while (i < len) {
            for (int curRow = 0; curRow < numRows && i < len; curRow++)
                grid[curRow] += s[i++];
            for (int curRow = numRows - 2; curRow > 0 && i < len; curRow--)
                grid[curRow] += s[i++];
        }
        string result;
        for (auto &row: grid)
            result += row;
        return result;
    }
};
