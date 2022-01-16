#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int last = -1, result = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i]) {
                result = last < 0 ? i : max(result, (i - last) / 2);
                last = i;
            }
        }
        result = max(result, (int) seats.size() - last - 1);
        return result;
    }
};
