#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/subarrays-with-k-different-integers/
 *
 */

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &nums, int K) {
        return atMost(nums, K) - atMost(nums, K - 1);
    }

    int atMost(vector<int> &nums, int K) {
        unordered_map<int, int> map;
        int i, ans;
        i = ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (map[nums[j]] == 0)
                K--; //Nếu chưa xuất hiện phần tử này thì thêm số phần tử xuất hiện
            map[nums[j]]++; //Thêm số lần xuất hiện
            while (K < 0) {
                map[nums[i]]--; //Giảm số lần xuất hiện
                if (map[nums[i]] == 0)
                    K++; //Nếu đây là lần xuất hiện cuối cùng thì giảm số phẩn tử xuất hiện
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};

int main() {
    vector<int> arr{1, 2, 1, 2, 3};
    Solution solution;
    cout << solution.subarraysWithKDistinct(arr, 2);
    return 0;
}
