from typing import List


class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        s = set(nums1)
        nums2.sort()
        for n in nums2:
            if n in s: return n
        return -1
