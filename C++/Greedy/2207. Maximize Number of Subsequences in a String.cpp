#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        return max(countSubsequence(pattern[0] + text, pattern),
                   countSubsequence(text + pattern[1], pattern));
    }

    long long countSubsequence(string text, string &pattern) {
        char c1 = pattern[0], c2 = pattern[1];
        long long result = 0, count = 0;
        for (char &c: text) {
            if (c == c2 && count)result += count;
            if (c == c1)count++;
        }
        return result;
    }
};
