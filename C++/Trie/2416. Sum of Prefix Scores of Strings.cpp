#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    vector<Trie *> child;
    int count = 0;
public:
    Trie() { child.resize(26); }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            delete child[i];
    }

    void insert(string &word) {
        Trie *cur = this;
        for (char &ch: word) {
            if (!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new Trie();
            cur = cur->child[ch - 'a'];
            cur->count++;
        }
    }

    int query(string &query) {
        Trie *cur = this;
        int res = 0;
        for (char c: query) {
            cur = cur->child[c - 'a'];
            res += cur->count;
        }
        return res;
    }
};

class Solution {
    Trie root;
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        for (string &w: words) root.insert(w);
        vector<int> res;
        for (string &w: words) res.push_back(root.query(w));
        return res;
    }
};
