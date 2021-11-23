#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/largest-component-size-by-common-factor/
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
    int largestComponentSize(vector<int> &nums) {
        parents.resize(100001);
        for (int i = 0; i < parents.size(); i++) parents[i] = i;
        for (int num: nums)
            for (int i = 2; i * i <= num; i++)
                if (num % i == 0) {
                    unionSet(num, i);
                    unionSet(num, num / i);
                }
        unordered_map<int, int> count;
        int result = 0;
        for (int num: nums)
            result = max(result, ++count[findSet(num)]);
        return result;
    }
};
