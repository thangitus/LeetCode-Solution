#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        set<int> set;
        copy_if(begin(s), end(s), inserter(set, begin(set)), ::isdigit);
        return set.size() > 1 ? *next(rbegin(set)) - '0' : -1;
    }
};
