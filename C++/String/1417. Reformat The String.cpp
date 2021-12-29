#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> digit, alpha;
        for (char c: s) {
            if (isdigit(c))
                digit.push_back(c);
            else alpha.push_back(c);
        }
        if (abs(int(digit.size() - alpha.size())) > 1)
            return "";
        string result;
        bool isAlpha = alpha.size() > digit.size();
        int i = 0, j = 0, k = 0;
        while (i < s.length()) {
            if (isAlpha)
                result += alpha[j++];
            else result += digit[k++];
            isAlpha = !isAlpha, i++;
        }
        return result;
    }
};