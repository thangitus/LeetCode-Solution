from typing import List


class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:
        sum = 0
        col, row = set(), set()
        for t, index, val in reversed(queries):
            if t == 0:
                if index not in row:
                    sum += (n - len(col)) * val
                    row.add(index)
            else:
                if index not in col:
                    sum += (n - len(row)) * val
                    col.add(index)
        return sum