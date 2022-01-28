#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
    struct TrieNode {
        unordered_map<char, TrieNode *> children;
        bool endOfWord;

        TrieNode() : endOfWord(false) {};
    };

private:
    TrieNode *root;

    bool searchTrie(TrieNode *cur, int i, string word) {
        if (i == word.length())
            return cur->endOfWord;
        if (word[i] != '.') {
            if (!cur->children.count(word[i]))
                return false;
            return searchTrie(cur->children[word[i]], i + 1, word);
        }

        for (auto it: cur->children)
            if (searchTrie(it.second, i + 1, word))
                return true;
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *curr = root;
        for (char ch: word) {
            if (curr->children.count(ch) == 0)
                curr->children[ch] = new TrieNode();

            curr = curr->children[ch];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        return searchTrie(root, 0, word);
    }
};
