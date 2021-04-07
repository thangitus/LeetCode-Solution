#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/count-number-of-nice-subarrays/
 * exactly(K) = atMost(K) - atMost(K-1)
 */
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }
};