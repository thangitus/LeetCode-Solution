#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/gcd-sort-of-an-array/
 */

class Solution {
private:
    vector<int> parents;

    int findSet(int u) {
        if (parents[u] != u)
            parents[u] = findSet(parents[u]);
        return parents[u];
    }

    void unionSet(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        parents[pv] = pu;
    }

public:
    bool gcdSort(vector<int> &nums) {
        parents.resize(100001);
        for (int i = 0; i < parents.size(); i++) parents[i] = i;
        for (int num: nums)
            for (int i = 2; i * i <= num; i++)
                if (num % i == 0) {
                    unionSet(num, i);
                    unionSet(num, num / i);
                }
        auto sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); i++)
            if (findSet(nums[i]) != findSet(sorted[i]))
                return false;
        return true;
    }
};
