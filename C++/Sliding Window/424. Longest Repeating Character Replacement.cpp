#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0, left = 0;
        vector<int> count(26);
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'A']++;
            while (true) {
                int maxCount = *max_element(count.begin(), count.end());
                if ((i - left + 1) - maxCount <= k)
                    break;
                else count[s[left++] - 'A']--;
            }
            result = max(result, i - left + 1);
        }
        return result;
    }
};
