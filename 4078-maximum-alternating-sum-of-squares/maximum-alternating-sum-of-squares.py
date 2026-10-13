import numpy as np


class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        sq = np.array(nums)

        sq = sq**2
        sq.sort()

        k = len(nums) // 2
        i = 0
        ans = 0

        for i in range(k):
            ans -= sq[i]

        for i in range(k, len(sq)):
            ans += sq[i]

        return int(ans)
