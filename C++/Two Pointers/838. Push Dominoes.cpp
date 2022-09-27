#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        dominoes = 'L' + dominoes + 'R';
        for (int left = 0, right = 1; right < dominoes.size(); ++right) {
            if (dominoes[right] == '.') continue;
            if (left > 0) res += dominoes[left];
            int countMid = right - left - 1;
            if (dominoes[left] == dominoes[right])
                res += string(countMid, dominoes[left]);
            else if (dominoes[left] == 'L' && dominoes[right] == 'R')
                res += string(countMid, '.');
            else
                res += (string(countMid / 2, 'R') +
                        string(countMid % 2, '.') + string(countMid / 2, 'L'));
            left = right;
        }
        return res;
    }
};
