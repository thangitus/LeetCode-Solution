#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class Trie {
    private:
        unordered_map<int, Trie *> child;
        int count = 0;
    public:
        void insert(vector<int> &row) {
            Trie *cur = this;
            for (int &i: row) {
                if (cur->child.find(i) == cur->child.end())
                    cur->child[i] = new Trie();
                cur = cur->child[i];
            }
            cur->count++;
        }

        int find(vector<int> &column) {
            Trie *cur = this;
            for (int i: column) {
                if (cur->child.find(i) == cur->child.end())
                    return 0;
                cur = cur->child[i];
            }
            return cur->count;
        }
    };


    Trie root;
public:
    int equalPairs(vector<vector<int>> &grid) {
        int res = 0, n = grid.size();
        for (auto &row: grid)
            root.insert(row);
        for (int j = 0; j < n; ++j) {
            vector<int> column;
            for (int i = 0; i < n; ++i)
                column.push_back(grid[i][j]);
            res += root.find(column);
        }
        return res;
    }
};