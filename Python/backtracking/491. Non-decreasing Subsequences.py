from typing import List


class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = set()

        def backtracking(cur, idx):
            nonlocal res
            if len(cur) > 1:
                res.add(tuple(cur))
            if idx >= len(nums): return

            if not cur or nums[idx] >= cur[-1]:
                backtracking(cur + [nums[idx]], idx + 1)
            backtracking(cur, idx + 1)

        backtracking([], 0)
        return res
