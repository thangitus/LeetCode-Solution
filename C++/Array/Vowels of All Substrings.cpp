#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/vowels-of-all-substrings/
 */

class Solution {
public:
    long long countVowels(string s) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u'};
        long long result = 0, n = s.length();
        vector<long long> arr;
        for (int i = 0; i < n; i++) {
            if (i == 0) arr.push_back(n);
            else arr.push_back((n - i) + arr[i - 1] - i);
        }
        for (int i = 0; i < n; i++)
            if (vowel.count(s[i]))
                result += arr[i];

        return result;
    }
};