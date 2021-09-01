#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/flatten-nested-list-iterator/
 * */



class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--)
            stack.push(nestedList[i]);
    }

    int next() {
        int top = stack.top().getInteger();
        stack.pop();
        return top;
    }

    bool hasNext() {
        while (!stack.empty()) {
            auto top = stack.top();
            if (top.isInteger()) return true;
            stack.pop();
            const auto &list = top.getList();
            for (int i = list.size() - 1; i >= 0; i--)
                stack.push(list[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */