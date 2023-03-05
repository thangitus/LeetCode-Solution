class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        mod, div = time % (n - 1), time // (n - 1)
        return mod + 1 if div % 2 == 0 else n - mod
