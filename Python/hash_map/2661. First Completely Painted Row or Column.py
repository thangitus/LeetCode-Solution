from typing import List


class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        n, m, rows, cols = len(mat), len(mat[0]), {}, {}
        count_row, count_col = [m] * n, [n] * m
        for i in range(n):
            for j, val in enumerate(mat[i]):
                rows[val] = i
                cols[val] = j
        for i, val in enumerate(arr):
            count_row[rows[val]] -= 1
            count_col[cols[val]] -= 1
            print(count_row, count_col)
            if count_row[rows[val]] == 0 or count_col[cols[val]] == 0:
                return i
        return -1
