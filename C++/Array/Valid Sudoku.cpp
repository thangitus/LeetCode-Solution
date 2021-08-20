#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/valid-sudoku/
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<bool> valid(10, true);
        vector<vector<bool>> blocks(9, valid);
        vector<vector<bool>> row(9, valid);
        vector<vector<bool>> col(9, valid);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int block = (i / 3 * 3 + j / 3);
                int num = board[i][j] - '0';
                if (blocks[block][num] && row[i][num] && col[j][num])
                    blocks[block][num] = row[i][num] = col[j][num] = false;
                else return false;
            }
        return true;
    }
};