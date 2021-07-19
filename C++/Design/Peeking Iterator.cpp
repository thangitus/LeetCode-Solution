#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/peeking-iterator/
 * */


class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    vector<int> nums;
    int i;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        this->nums = nums;
        i = 0;
    }

    int peek() {
        return nums[i];
    }

    int next() {
        return nums[i++];
    }

    bool hasNext() const {
        return i < nums.size();
    }
};