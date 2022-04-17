#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string str;
            for (int i = 0; i < s.length(); i += k) {
                string tmp;
                if (i < s.length() - k)
                    tmp = s.substr(i, k);
                else tmp = s.substr(i);
                int sum = 0;
                for (char j : tmp)
                    sum += (j - '0');
                str += to_string(sum);
            }
            s = str;
        }
        return s;
    }
};
