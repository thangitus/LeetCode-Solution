#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/excel-sheet-column-title/
 * */

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber) {
            columnNumber -= 1;
            result += char(columnNumber % 26 + 'A');
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};