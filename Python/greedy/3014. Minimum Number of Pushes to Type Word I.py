class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        return (n +
                max(0, (n - 8)) +
                max(0, (n - 16)) +
                max(0, (n - 24)) +
                max(0, n - 26))
