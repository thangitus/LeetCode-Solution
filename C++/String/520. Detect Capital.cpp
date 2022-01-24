#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for (char &c: word)
            capitalCount += (bool) isupper(c);
        return (!capitalCount ||
                (capitalCount == 1 && 'Z' - word[0] >= 0) ||
                capitalCount == word.size());
    }
};
