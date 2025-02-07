class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        count = {}
        res = 0
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                product = nums[i] * nums[j]
                count.setdefault(product, 0)
                res += count[product] * 8
                count[product] = count[product] + 1
        return res
