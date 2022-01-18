#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> result(m, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            queue<int> pos;
            for (int j = m - 1; j >= 0; --j) {
                if (box[i][j] == '*')
                    pos = queue<int>();
                else {
                    pos.push(j);
                    if (box[i][j] == '#') {
                        box[i][j] = '.';
                        box[i][pos.front()] = '#';
                        pos.pop();
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = m - 1; j >= 0; --j)
                result[j][n - i - 1] = box[i][j];

        return result;
    }
};
