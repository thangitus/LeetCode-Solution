from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        res, end = 0, float('-inf')
        for start, cur_end in points:
            if start > end:
                res += 1
                end = cur_end
        return res