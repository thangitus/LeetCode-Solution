#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int result = 0;

    int maxLength(vector<string> &arr) {
        dfs(0, arr, 0);
        return result;
    }

    void dfs(int cur, vector<string> &arr, int i) {
        if (i == arr.size()) {
            int count = 0;
            while (cur) {
                count += (cur & 1);
                cur >>= 1;
            }
            result = max(result, count);
            return;
        }
        dfs(cur, arr, i + 1); //skip arr[i]
        int num = 0, pos;
        for (char c: arr[i]) {
            pos = c - 'a';
            if ((num >> pos) & 1) //duplicate character in current string -> skip
                return;
            num |= (1 << pos);
        }
        if (!(num & cur)) //check duplicate character with previous string
            dfs(cur | num, arr, i + 1);
    }
};
