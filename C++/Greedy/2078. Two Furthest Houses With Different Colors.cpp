#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &colors) {
        int n = colors.size(), left = 0, right = n - 1;
        while (colors[0] == colors[right]) right--;
        while (colors[left] == colors[n - 1]) left++;
        return max(right, n - left - 1);
    }
};
