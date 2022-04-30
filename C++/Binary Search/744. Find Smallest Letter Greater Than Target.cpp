#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int left = 0, right = letters.size(), pos = right;
        while (left < right) {
            int mid = (left + right) / 2;
            if (letters[mid] > target)
                pos = mid, right = mid;
            else left = mid + 1;
        }
        pos = pos < letters.size() ? pos : 0;
        return letters[pos];
    }
};
