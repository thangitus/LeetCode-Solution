from typing import List


class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        n, count = len(barcodes), {}
        res, k = [0] * n, 0
        for i in barcodes:
            count.setdefault(i, 0)
            count[i] += 1
        count = sorted(count.items(), key=lambda x: x[1], reverse=True)
        for i in range(len(count)):
            for j in range(count[i][1]):
                res[k] = count[i][0]
                k += 2
                if k >= n: k = 1
        return res
