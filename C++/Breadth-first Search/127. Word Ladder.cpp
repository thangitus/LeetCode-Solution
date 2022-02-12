#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int n = wordList.size(), result = 0;
        vector<vector<int>> graph(n);
        bool existEndWord = false;
        for (auto &word: wordList)
            if (word == endWord) {
                existEndWord = true;
                break;
            }
        if (!existEndWord) return 0;
        queue<int> queue;
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (isAdjacent(beginWord, wordList[i]))
                queue.push(i);
            for (int j = i + 1; j < n; ++j) {
                if (isAdjacent(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        while (!queue.empty()) {
            result++;
            for (int k = queue.size(); k > 0; --k) {
                int u = queue.front();
                queue.pop();
                string cur = wordList[u];
                if (cur == endWord) return result;
                visited[u] = true;
                for (int &v: graph[u])
                    if (!visited[v])
                        queue.push(v);
            }
        }
        return 0;
    }

    bool isAdjacent(string &word1, string &word2) const {
        int len1 = word1.length(), len2 = word2.length(), diff = abs(len1 - len2);
        for (int k = 0; k < min(len1, len2); ++k)
            diff += word1[k] != word2[k];
        return diff <= 1;
    }
};
