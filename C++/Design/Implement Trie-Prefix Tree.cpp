#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/design-hashmap/
 * */

class Trie {
private:
    vector<Trie *> child;
    bool isWord = false;
public:
    Trie() {
        child.resize(26);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            delete child[i];
    }

    void insert(string word) {
        Trie *cur = this;
        for (char &ch:word) {
            if (!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new Trie();
            cur = cur->child[ch - 'a'];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Trie *cur = this;
        for (char &ch:word) {
            if (!cur->child[ch - 'a'])
                return false;
            cur = cur->child[ch - 'a'];
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        Trie *cur = this;
        for (char &ch:prefix) {
            if (!cur->child[ch - 'a'])
                return false;
            cur = cur->child[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

