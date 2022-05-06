#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        unordered_set<int> set;
        for (int &num: arr) {
            if (set.count(num * 2)) return true;
            if (!(num & 1) && set.count(num / 2))
                return true;
            set.insert(num);
        }
        return false;
    }
};
