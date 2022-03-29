#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int result = 0;
        for (int &num: nums) {
            int cur = abs(num);
            if (nums[cur] < 0) {
                result = cur;
                break;
            }
            nums[cur] *= -1;
        }
        for (int &num: nums)
            num = abs(num);
        return result;
    }
};