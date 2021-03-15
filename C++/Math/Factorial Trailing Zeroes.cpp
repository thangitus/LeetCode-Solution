#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/factorial-trailing-zeroes/
/*
 *Ta có số số 0 ở đuôi bằng số lần xuất hiện của 5 khi phân tích n! thành các số nguyên tố
 * Mà n!=1*..*n nên ta sẽ đếm số thừa số nguyên tố bằng 5
 * */
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i += 5) {
            int j = i;
            while (j >= 5 && j % 5 == 0) {
                ans++;
                j /= 5;
            }
        }
        return ans;
    }
};

// Recursive
class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        return n / 5 + trailingZeroes(n / 5);
    }
};
