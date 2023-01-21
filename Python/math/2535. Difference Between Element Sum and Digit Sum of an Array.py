from typing import List


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        digitSum = 0
        for num in nums:
            while num > 0:
                digitSum += num % 10
                num //= 10
        return sum(nums) - digitSum
