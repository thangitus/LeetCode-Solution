#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    void buildTree(vector<int> &nums, int left, int right, int index) {
        if (left == right) {
            tree[index] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(nums, left, mid, 2 * index + 1);
        buildTree(nums, mid + 1, right, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int sumRange(int left, int right, int from, int to, int index) {
        if (from <= left && to >= right) return tree[index];
        if (from > right || to < left) return 0;
        int mid = left + (right - left) / 2;
        return sumRange(left, mid, from, to, 2 * index + 1) +
               sumRange(mid + 1, right, from, to, 2 * index + 2);
    }

    void update(int left, int right, int index, int &pos, int &value) {
        if (pos < left || right < pos) return;
        if (left == right) {
            tree[index] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (pos <= mid) update(left, mid, 2 * index + 1, pos, value);
        else update(mid + 1, right, 2 * index + 2, pos, value);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    vector<int> tree;
    int n;
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        int h = ceil(log2(n)), size = pow(2, h + 1) - 1;
        tree.resize(size);
        buildTree(nums, 0, n - 1, 0);
    }

    void update(int index, int val) {
        update(0, n - 1, 0, index, val);
    }


    int sumRange(int left, int right) {
        return sumRange(0, n - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */