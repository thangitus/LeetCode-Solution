#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while (i <= max(memory1, memory2)) {
            if (memory2 > memory1)
                memory2 -= i;
            else memory1 -= i;
            i++;
        }
        return {i, memory1, memory2};
    }
};
