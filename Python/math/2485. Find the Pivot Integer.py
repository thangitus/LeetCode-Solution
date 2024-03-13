import math


class Solution:
    def pivotInteger(self, n: int) -> int:
        """
            Let's call total the sum of the numbers from 1 to n (using the arithmetic progression formula)
            Let: 
                prefix be (the sum of the numbers from 1 to pivot - 1) + pivot / 2, 
                suffix be (the sum of the numbers from pivot + 1 to n) + pivot / 2  
            prefix = (1 + pivot - 1) * (pivot - 1) / 2 + pivot / 2 
                    = pivot * (pivot - 1) / 2 + pivot / 2 
                    = (pivot * pivot) / 2  
            We have:
                total = prefix + suffix 
                => total = 2 * prefix = pivot * pivot 
                => pivot = sqrt(total)
        """
        total = (1 + n) * n / 2
        pivot = math.sqrt(total)
        return int(pivot) if pivot == int(pivot) else -1
