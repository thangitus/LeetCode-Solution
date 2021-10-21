#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/insert-delete-getrandom-o1/
 * */

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> map;
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        int n = nums.size();
        map[val] = n;
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        int index = map[val];
        map[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

