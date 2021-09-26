#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
 * @var resultZero: Count number of operation if string start with '0'
 * @var resultOne: Count number of operation if string start with '1'
 * */

class Solution {
public:
    int minOperations(string s) {
        int resultZero = 0, resultOne = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2) {
                resultZero += s[i] != '0';
                resultOne += s[i] != '1';
            } else {
                resultZero += s[i] == '0';
                resultOne += s[i] == '1';
            }
        }
        return min(resultOne, resultZero);
    }
}
