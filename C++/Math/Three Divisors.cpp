#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/three-divisors/
 * */

class Solution {
public:
    bool isThree(int n) {
        int count = 2;
        for (int i = 2; i < n && count <= 3; i++)
            count += !(n % i);
        return count == 3;
    }
};