#include <bits/stdc++.h>

using namespace std;

class Solution {
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

        int search(string &query) {
            Trie *cur = this;
            for (char &c: query) {
                if (!cur->child[c - 'a'])
                    return -1;
                cur = cur->child[c - 'a'];
            }
            return cur->isWord ? 1 : 0;
        }
    };

    Trie root;
public:
    int n, m;
    bool visited[12][12];
    unordered_set<string> result;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        n = board.size(), m = board[0].size();
        memset(visited, 0, sizeof(visited));
        string cur;
        for (string &w: words) root.insert(w);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cur = board[i][j];
                backtracking(i, j, board, cur);
            }
        return {result.begin(), result.end()};
    }

    void backtracking(int x, int y, vector<vector<char>> &board, string &query) {
        int search = root.search(query);
        if (search == 1) result.insert(query);
        else if (search == -1) return;
        visited[x][y] = true;

        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        for (int k = 0; k < 4; k++) {
            int newX = dx[k] + x, newY = dy[k] + y;
            if (newX < 0 || newY < 0 || newX >= n || newY >= m || visited[newX][newY]) continue;
            query.push_back(board[newX][newY]);
            backtracking(newX, newY, board, query);
            query.pop_back();
        }
        visited[x][y] = false;
    }
};
