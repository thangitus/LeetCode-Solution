from typing import List
import numpy as np


class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        nums.reverse()
        n = 1050
        primes = np.arange(n)
        primes[:2] = 0
        for i in range(2, int(np.sqrt(n)) + 1):
            primes[i * i:n:i] = 0
        primes = np.nonzero(primes)[0].tolist()
        for i in range(1, len(nums)):
            if nums[i] >= nums[i - 1]:
                prime = primes[np.searchsorted(primes, nums[i] - nums[i - 1] + 1, side='left')]
                nums[i] -= prime
            if nums[i] >= nums[i - 1] or nums[i] <= 0: return False
        return True
