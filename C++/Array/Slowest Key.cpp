#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/slowest-key/
 */

class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        char result = 'a';
        int curr = 0;
        vector<int> nums(26);
        for (int i = 0; i < releaseTimes.size(); i++) {
            nums[keysPressed[i] - 'a'] = max(nums[keysPressed[i] - 'a'], releaseTimes[i] - curr);
            if (nums[keysPressed[i] - 'a'] > nums[result - 'a'])
                result = keysPressed[i];
            else if (nums[keysPressed[i] - 'a'] == nums[result - 'a'])
                result = max(result, keysPressed[i]);
            curr = releaseTimes[i];
        }
        return result;
    }
};
