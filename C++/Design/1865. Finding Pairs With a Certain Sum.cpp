#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"


using namespace std;

class FindSumPairs {
public:
    unordered_map<int, int> count1, count2;
    vector<int> nums2;

    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        for (int n: nums1) count1[n]++;
        for (int n: nums2) count2[n]++;
        this->nums2 = nums2;
    }

    void add(int index, int val) {
        int &num = nums2[index];
        count2[num]--, num += val, count2[num]++;
    }

    int count(int tot) {
        int res = 0;
        for (auto &i: count1)
            res += (i.second * count2[tot - i.first]);
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */