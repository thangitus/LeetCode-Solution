#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int left = max(ax1, bx1), right = min(ax2, bx2);
        int bottom = max(ay1, by1), top = min(ay2, by2);
        int aArea = computeArea(ax1, ay1, ax2, ay2);
        int bArea = computeArea(bx1, by1, bx2, by2);
        int xOverlap = right - left, yOverlap = top - bottom, overlapArea = 0;
        if (xOverlap > 0 && yOverlap > 0) overlapArea = xOverlap * yOverlap;
        return aArea + bArea - overlapArea;

    }

    int computeArea(int ax1, int ay1, int ax2, int ay2) {
        return (ax2 - ax1) * (ay2 - ay1);
    }
};