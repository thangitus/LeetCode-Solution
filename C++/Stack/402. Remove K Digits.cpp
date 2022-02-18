#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size())
            return "0";
        int remain = num.size() - k, i = 0;
        string res;
        for (char &c: num) {
            while (k > 0 && !res.empty() && res.back() > c)
                res.pop_back(), k--;
            res.push_back(c);
        }
        while (res.length() > remain)
            res.pop_back();
        while (i < res.length() && res[i] == '0')
            i++;
        return i == res.length() ? "0" : res.substr(i);
    }
};
