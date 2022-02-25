#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int row, int col, int newColor) {
        if (image[row][col] == newColor) return image;
        int oldColor = image[row][col];
        image[row][col] = newColor;
        if (row > 0 && image[row - 1][col] == oldColor)
            floodFill(image, row - 1, col, newColor);

        if (row < image.size() - 1 && image[row + 1][col] == oldColor)
            floodFill(image, row + 1, col, newColor);

        if (col > 0 && image[row][col - 1] == oldColor)
            floodFill(image, row, col - 1, newColor);

        if (col < image[0].size() - 1 && image[row][col + 1] == oldColor)
            floodFill(image, row, col + 1, newColor);
        return image;
    }
};