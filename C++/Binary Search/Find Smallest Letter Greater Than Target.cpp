#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 * */

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int pos = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        pos = pos < letters.size() ? pos : 0;
        return letters[pos];
    }
};