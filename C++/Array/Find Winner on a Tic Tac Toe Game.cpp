#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
 */

class Solution {
public:
    string tictactoe(vector<vector<int>> &moves) {
        vector<int> A(8), B(8); //3 rows, 3 cols, 2 diagonals
        for (int i = 0; i < moves.size(); i++) {
            auto &player = (i % 2) ? B : A;
            int x = moves[i][0], y = moves[i][1];
            player[x]++, player[y + 3]++;
            if (x == y) player[6]++;
            if (x == 2 - y) player[7]++;
        }
        for (int i = 0; i < 8; i++)
            if (A[i] == 3) return "A";
            else if (B[i] == 3) return "B";
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
