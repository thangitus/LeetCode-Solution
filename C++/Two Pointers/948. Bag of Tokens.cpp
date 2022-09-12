#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int score = 0, left = 0, right = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while (left <= right) {
            if (power >= tokens[left]) score++, power -= tokens[left++];
            else if (right - left > 1 && score > 0) score--, power += tokens[right--];
            else break;
        }
        return score;
    }
};
