#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/max-consecutive-ones-iii/
 */
class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int ans, i, count;
        ans = i = count = 0;
        for (int j = 0; j < A.size(); j++) {
            if (!A[j]) count++;
            while (count > K)
                if (!A[i++])count--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};