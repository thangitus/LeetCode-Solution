#include <bits/stdc++.h>

using namespace std;

class WordFilter {
private:
    class Trie {
    private:
        vector<Trie *> child;
        int index;
    public:
        Trie() { child.resize(27); }

        ~Trie() {
            for (int i = 0; i < 27; i++)
                delete child[i];
        }

        void insert(string &word, int i) {
            Trie *cur = this;
            for (char &ch: word) {
                if (!cur->child[ch - 'a'])
                    cur->child[ch - 'a'] = new Trie();
                cur = cur->child[ch - 'a'];
                cur->index = i;
            }
        }

        int find(string &query) {
            Trie *cur = this;
            for (char c: query) {
                if (!cur->child[c - 'a'])
                    return -1;
                cur = cur->child[c - 'a'];
            }
            return cur->index;
        }
    };


    Trie root;
public:
    WordFilter(vector<string> &words) {
        for (auto i = 0; i < words.size(); ++i) {
            string prefix, suffix = words[i];
            reverse(suffix.begin(), suffix.end());
            for (int k = 0; k < words[i].length(); ++k) {
                prefix += words[i][k];
                string word = prefix;
                word.append("{").append(suffix);
                root.insert(word, i);
            }
        }
    }

    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        string word = prefix + '{' + suffix;
        return root.find(word);
    }
};
