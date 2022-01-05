#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtracking(0, s, path, result);
        return result;
    }

    void backtracking(int start, string s, vector<string> &path, vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtracking(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++, right--;
        }
        return true;
    }
};
