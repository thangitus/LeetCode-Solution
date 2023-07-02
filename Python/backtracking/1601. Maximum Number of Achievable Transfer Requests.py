from typing import List


class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        res = 0

        def backtracking(cur, idx, count):
            nonlocal res
            if idx >= len(requests):
                if all(x == 0 for x in cur):
                    res = max(res, count)
                return

            a, b = requests[idx]
            cur[a] -= 1
            cur[b] += 1
            backtracking(cur, idx + 1, count + 1)
            cur[a] += 1
            cur[b] -= 1

            backtracking(cur, idx + 1, count)

        backtracking([0] * n, 0, 0)
        return res
