#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int row) {
        string originalText;
        int i = 0, j = 0, col = encodedText.length() / row, startCol = 0;
        while (j < col) {
            originalText.push_back(encodedText[i * col + j]);
            j++, i++;
            if (i == row || j == col)
                i = 0, j = ++startCol;
        }
        while (originalText.back() == ' ')originalText.pop_back();
        return originalText;
    }
};
