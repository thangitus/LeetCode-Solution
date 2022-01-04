#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        vector<string> words1, words2;
        string word;
        while (ss1 >> word)
            words1.push_back(word);
        while (ss2 >> word)
            words2.push_back(word);
        if (words1.size() < words2.size())
            swap(words1, words2);

        int m = words1.size(), n = words2.size(), left = 0, right = n - 1;
        while (left < n && words1[left] == words2[left]) ++left;
        while (right >= left && words1[m - (n - right)] == words2[right]) --right;
        return right < left;
    }
};
