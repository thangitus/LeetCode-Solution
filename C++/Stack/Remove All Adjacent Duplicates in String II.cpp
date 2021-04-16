#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * use pair to count the number of occurrences of the character
 * */

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        for (char &ch:s) {
            if (stack.empty())
                stack.push(make_pair(ch, 1));
            else {
                auto top = stack.top();
                if (top.first == ch)
                    stack.push(make_pair(ch, top.second + 1));
                else stack.push(make_pair(ch, 1));
            }

            if (stack.top().second == k) {
                for (int i = 0; i < k; i++)
                    stack.pop();
            }
        }

        string ans;
        while (!stack.empty()) {
            auto top = stack.top();
            ans += top.first;
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};