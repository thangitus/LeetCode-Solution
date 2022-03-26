#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string result;
        while (i < word1.length() && j < word2.length()) {
            if (word1[i] > word2[j])
                result += word1[i++];
            else if (word2[j] > word1[i])
                result += word2[j++];
            else {
                if (word1.substr(i) > word2.substr(j))
                    result += word1[i++];
                else result += word2[j++];
            }
        }
        result += word1.substr(i);
        result += word2.substr(j);
        return result;
    }
};
