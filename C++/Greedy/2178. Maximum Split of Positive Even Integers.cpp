#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1 || finalSum < 2) return {};
        vector<long long> result;
        long long cur = 2;
        while (finalSum) {
            if (finalSum - cur <= cur) {
                result.push_back(finalSum);
                break;
            }
            result.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        return result;
    }
};