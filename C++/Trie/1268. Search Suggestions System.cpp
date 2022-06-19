#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class Trie {
    private:
        vector<Trie *> child;
        bool isWord = false;

        static void dfs(Trie *node, string &word, vector<string> &result) {
            if (result.size() == 3) return;
            if (node == nullptr) return;
            if (node->isWord) result.push_back(word);
            for (char c = 'a'; c <= 'z'; ++c) {
                word += c;
                dfs(node->child[c - 'a'], word, result);
                word.pop_back();
            }
        }

    public:
        Trie() { child.resize(27); }

        ~Trie() {
            for (int i = 0; i < 27; i++)
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

        vector<string> find(string &query) {
            Trie *cur = this;
            vector<string> result;
            for (char c: query) {
                if (!cur->child[c - 'a'])
                    return {};
                cur = cur->child[c - 'a'];
            }
            dfs(cur, query, result);
            return result;
        }
    };

    Trie root;
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        for (string &product: products) root.insert(product);
        vector<vector<string>> result;
        string word;
        for (char &c: searchWord) {
            word += c;
            result.push_back(root.find(word));
        }
        return result;
    }
};
