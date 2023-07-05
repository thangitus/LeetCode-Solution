from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        map = {}
        for i, num in enumerate(nums):
            if num in map and i - map[num] <= k:
                return True
            map[num] = i
        return False
