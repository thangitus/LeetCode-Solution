from typing import List


class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        items = [arr[n // 4], arr[n // 2], arr[n * 3 // 4]]
        for item in items:
            l, r = self.findFirstOccurrence(arr, item), self.findLastOccurrence(arr, item)
            if r - l + 1 > n // 4:
                return item
        return -1

    def findFirstOccurrence(self, arr: List[int], target: int) -> int:
        l, r = 0, len(arr) - 1
        while l < r:
            mid = (l + r) // 2
            if arr[mid] < target:
                l = mid + 1
            else:
                r = mid
        return l if arr[l] == target else -1

    def findLastOccurrence(self, arr: List[int], target: int) -> int:
        l, r = 0, len(arr) - 1
        while l < r:
            mid = (l + r + 1) // 2
            if arr[mid] > target:
                r = mid - 1
            else:
                l = mid
        return l if arr[l] == target else -1
