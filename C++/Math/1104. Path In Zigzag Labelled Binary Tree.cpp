
#include <bits/stdc++.h>

using namespace std;

/**
 * If the tree is numbered left-to-right (not zigzag),
 * the parent's label can be always determined as label/2.
 * For zigzag, we need to "invert" the parent label.
 * */

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        while (true) {
            result.push_back(label);
            if (label == 1) break;
            int p = label / 2, h = log2(label);
            int minVal = 1 << (h - 1), maxVal = (1 << h) - 1;
            int id = maxVal - p, parent = minVal + id;
            label = parent;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
