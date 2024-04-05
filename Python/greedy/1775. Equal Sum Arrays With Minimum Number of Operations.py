from typing import List


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2 = sum(nums1), sum(nums2)
        if sum1 == sum2:
            return 0
        if sum1 > sum2:
            return self.minOperations(nums2, nums1)
        if len(nums2) > 6 * len(nums1):
            return -1
        diff = sum2 - sum1
        count = [0] * 6
        for num in nums1:
            count[6 - num] += 1
        for num in nums2:
            count[num - 1] += 1
        res = 0
        for i in range(5, 0, -1):
            while diff > 0 and count[i] > 0:
                diff -= i
                count[i] -= 1
                res += 1
        return res
