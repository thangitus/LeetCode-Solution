#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 */

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue<vector<int>> pq;
        for (int &num1 : nums1) {
            for (int &num2 : nums2) {
                int sum = num1 + num2;
                if (pq.size() < k) pq.push({sum, num1, num2});
                else if (sum < pq.top()[0]) {
                    pq.pop();
                    pq.push({sum, num1, num2});
                } else break;
            }
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
