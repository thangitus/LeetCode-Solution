class Solution:
    def longestString(self, x: int, y: int, z: int) -> int:
        mn = min(x, y)
        return (x + y + z) * 2 if x == y else (mn * 2 + z * 2 + (mn + 1) * 2)
