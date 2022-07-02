#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int> &hCuts, vector<int> &vCuts) {
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        long hMax = max(hCuts[0] - 0, h - hCuts.back());
        long wMax = max(vCuts[0] - 0, w - vCuts.back());
        long mod = 1e9 + 7;
        for (int i = 1; i < hCuts.size(); ++i)
            hMax = max(hMax, (long) hCuts[i] - hCuts[i - 1]);
        for (int i = 1; i < vCuts.size(); ++i)
            wMax = max(wMax, (long) vCuts[i] - vCuts[i - 1]);
        return (hMax * wMax) % mod;
    }
};
