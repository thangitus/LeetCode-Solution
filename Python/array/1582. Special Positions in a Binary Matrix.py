from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        n, m, res = len(mat), len(mat[0]), 0
        row, col = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                row[i] += mat[i][j]
                col[j] += mat[i][j]
        for i in range(n):
            for j in range(m):
                res += 1 if mat[i][j] and row[i] == 1 and col[j] == 1 else 0
        return res
