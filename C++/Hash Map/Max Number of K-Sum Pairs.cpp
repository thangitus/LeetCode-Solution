#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/max-number-of-k-sum-pairs/
 * */
class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int ans = 0;
        map<int, int> map;
        for (int &i:nums) map[i]++;
        for (auto &item:map) {
            if (item.first * 2 == k)ans += item.second / 2;
            else {
                int b = map[k - item.first];
                ans += min(item.second, b);
            }
            item.second = 0;
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {29, 26, 81, 70, 75, 4, 48, 38, 22, 10, 51, 62, 17, 50, 7, 7, 24, 61, 54, 44, 30, 29, 66, 83, 6,
                       45, 24, 49, 42, 31, 10, 6, 88, 48, 34, 10, 54, 56, 80, 41, 19};
    Solution solution;
    cout << solution.maxOperations(arr, 12);
    return 0;
}