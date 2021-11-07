#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-vowel-substrings-of-a-string/
 */

class Solution {
public:
    int countVowelSubstrings(string s) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> seen;
            int count = 0;
            for (int j = i; j < s.size(); j++) {
                if (!vowel.count(s[j])) break;
                if (!seen.count(s[j])) count++;
                seen.insert(s[j]);
                if (count == 5) result++;

            }
        }
        return result;
    }
};