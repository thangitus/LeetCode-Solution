from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:

        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        res = []
        for a in asteroids:
            while res and a < 0 < res[-1]:
                if res[-1] < -a:
                    res.pop()
                    continue
                elif res[-1] == -a:
                    res.pop()
                break
            else:
                res.append(a)
        return res
