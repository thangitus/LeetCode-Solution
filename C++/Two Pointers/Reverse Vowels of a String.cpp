#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/reverse-vowels-of-a-string/
 */

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        while (left < right) {
            while (vowels.find(tolower(s[left])) == vowels.end() && left < right) left++;
            while (vowels.find(tolower(s[right])) == vowels.end() && left < right) right--;
            if (left < right)
                swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};