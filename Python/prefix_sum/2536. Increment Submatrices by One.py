from typing import List


class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            for r in range(r1, r2 + 1):
                res[r][c1] += 1
                if c2 + 1 < n: res[r][c2 + 1] -= 1

        for r in range(n):
            for c in range(1, n):
                res[r][c] += res[r][c - 1]
        return res
