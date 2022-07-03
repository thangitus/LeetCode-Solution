#include <bits/stdc++.h>
#include "../Linked List/ListNode.h"

using namespace std;


class Solution {
public:
    ListNode *cur;

    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> result(m, vector<int>(n));
        int rowBegin, colBegin, rowEnd, colEnd;
        cur = head;
        rowBegin = colBegin = 0, rowEnd = m - 1, colEnd = n - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++)  // Traverse Right
                result[rowBegin][j] = getValue(cur);

            for (int i = ++rowBegin; i <= rowEnd; i++) // Traverse Down
                result[i][colEnd] = getValue(cur);

            for (int j = --colEnd; rowBegin <= rowEnd && j >= colBegin; j--) // Traverse Left
                result[rowEnd][j] = getValue(cur);

            for (int i = --rowEnd; colBegin <= colEnd && i >= rowBegin; i--) // Traver Up
                result[i][colBegin] = getValue(cur);

            colBegin++;
        }
        return result;
    }

    int getValue(ListNode *node) {
        if (!node) return -1;
        cur = cur->next;
        return node->val;
    }
};
