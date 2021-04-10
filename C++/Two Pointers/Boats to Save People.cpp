#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/boats-to-save-people/
 */

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int ans, i, j = people.size() - 1;
        ans = i = 0;
        while (i <= j) {
            int sum = people[j];
            if (j > 0 && sum + people[j - 1] <= limit)
                j--;
            else if (sum + people[i] <= limit)
                i++;
            j--;
            ans++;
        }
        return ans;
    }
};