from typing import List


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        count = [0] * 2
        for i in range(len(nums1)):
            diff = nums1[i] - nums2[i]
            if diff == 0: continue
            if k == 0 or diff % k != 0: return -1
            if diff > 0:
                count[0] += diff // k
            elif diff < 0:
                count[1] += diff // k
        return count[0] if count[0] == -count[1] else -1
