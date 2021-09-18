#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/pascals-triangle-ii/
 * res(n,i) = C(n,i) = (n-i+1)*C(n,i-1)/i
 * */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++)
            res[i] = (long) res[i - 1] * (rowIndex - i + 1) / i;
        return res;
    }
};
