#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> set;
        string num;
        for (int i = 0; i < word.length(); ++i) {
            if (isdigit(word[i])) {
                if (word[i] != '0' || num != "" || i == word.length() - 1 || isalpha(word[i + 1]))
                    num += word[i];
            } else if (!num.empty())
                set.insert(num), num = "";
        }
        if (!num.empty()) set.insert(num);
        return set.size();
    }
};
