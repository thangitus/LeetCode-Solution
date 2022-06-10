#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(255, -1);
        int result = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            char chr = s[right];
            if (pos[chr] != -1 && pos[chr] >= left)
                left = pos[chr] + 1;
            result = max(result, right - left + 1);
            pos[chr] = right;
        }
        return result;
    }
};
