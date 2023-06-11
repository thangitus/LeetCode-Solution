class Solution:
    def smallestString(self, s: str) -> str:
        chars = list(s)
        n, i = len(chars), 0
        while i < n and chars[i] == 'a': i += 1
        while i < n and chars[i] != 'a':
            chars[i] = chr(ord(chars[i]) - 1)
            i += 1
        if chars == list(s): chars[-1] = 'z'
        return "".join(chars)
