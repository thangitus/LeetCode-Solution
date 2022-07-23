#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    //Merge descending
    void merge(vector<pair<int, int>> &nums, vector<int> &res, int left, int right, int mid) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, cur = 0;
        while (i <= mid && j <= right) {
            if (nums[i].first > nums[j].first) {
                res[nums[i].second] += (right - j + 1);
                temp[cur++] = nums[i++];
            } else temp[cur++] = nums[j++];
        }
        while (i <= mid) temp[cur++] = nums[i++];
        while (j <= right) temp[cur++] = nums[j++];
        for (int k = left; k <= right; ++k) nums[k] = temp[k - left];
    }

    void mergeSort(vector<pair<int, int>> &nums, vector<int> &res, int left, int right) {
        if (left >= right) return;
        int mid = (right - left) / 2 + left;
        mergeSort(nums, res, left, mid);
        mergeSort(nums, res, mid + 1, right);
        merge(nums, res, left, right, mid);
    }

public:
    vector<int> countSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n);
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = {arr[i], i};
        mergeSort(nums, res, 0, n - 1);
        return res;
    }
};