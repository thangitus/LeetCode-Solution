#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfPairs(vector<string> &nums, string target) {
        int prefix[101] = {}, suffix[101] = {}, result = 0, targetLength = target.length();
        for (auto &num: nums) {
            int len = num.length();
            if (len < targetLength) {
                bool isPrefix = target.compare(0, len, num) == 0;
                bool isSuffix = target.compare(targetLength - len, len, num) == 0;
                result += (isPrefix ? suffix[targetLength - len] : 0);
                result += (isSuffix ? prefix[targetLength - len] : 0);
                prefix[len] += isPrefix, suffix[len] += isSuffix;
            }
        }
        return result;
    }
};
