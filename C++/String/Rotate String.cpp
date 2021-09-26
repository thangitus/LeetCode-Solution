#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/rotate-string/
 * */

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
