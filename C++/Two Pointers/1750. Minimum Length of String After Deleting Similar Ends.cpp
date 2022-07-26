#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            char l = s[left], r = s[right];
            if (l != r) break;
            while (left <= right && s[left] == l) left++;
            while (left <= right && s[right] == r) right--;
        }
        return right - left + 1;
    }
};