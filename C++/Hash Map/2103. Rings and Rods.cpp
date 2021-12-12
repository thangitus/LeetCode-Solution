#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<set<char>> arr(10);
        int result = 0;
        for (int i = 0; i < rings.length() / 2; i++)
            arr[rings[i * 2 + 1] - '0'].insert(rings[i * 2]);
        for (auto item: arr)
            result += item.size() == 3;
        return result;
    }
};