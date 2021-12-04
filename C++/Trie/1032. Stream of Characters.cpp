#include <bits/stdc++.h>

using namespace std;

class StreamChecker {
private:
    class Trie {
    private:
        vector<Trie *> child;
        bool isWord = false;
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
            }
            cur->isWord = true;
        }

        bool startsWith(string &query) {
            Trie *cur = this;
            for (int i = query.length() - 1; i >= 0; i--) {
                if (cur->isWord) return true;
                if (!cur->child[query[i] - 'a'])
                    return false;
                cur = cur->child[query[i] - 'a'];
            }
            return cur->isWord;
        }
    };


    Trie root;
    string queryStr;
public:
    StreamChecker(vector<string> &words) {
        for (string &word: words) {
            reverse(word.begin(), word.end());
            root.insert(word);
        }
    }

    bool query(char letter) {
        queryStr += letter;
        return root.startsWith(queryStr);
    }
};
