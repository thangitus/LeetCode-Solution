#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        long long n = arr.size(), res = 0, mod = 1e9 + 7;
        stack<pair<long long, int>> prev, next;
        vector<long long> left(n), right(n);
        for (int i = 0; i < n; ++i) left[i] = i + 1, right[i] = n - i;
        for (int i = 0; i < n; ++i) {
            while (!prev.empty() && prev.top().first > arr[i]) prev.pop();
            left[i] = prev.empty() ? i + 1 : i - prev.top().second;
            prev.push({arr[i], i});

            while (!next.empty() && next.top().first > arr[i]) {
                auto top = next.top();
                next.pop();
                right[top.second] = i - top.second;
            }
            next.push({arr[i], i});
        }

        for (int i = 0; i < n; ++i)
            res = (res + arr[i] * left[i] * right[i]) % mod;
        return (int) res;
    }
};
