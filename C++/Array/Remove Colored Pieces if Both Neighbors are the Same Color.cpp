#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
 */

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                alice++;
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                bob++;
        }
        return alice > bob;
    }
};