from typing import List

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        dic = {}
        c = s = 0
        for num in nums:
            s += num
            if s == goal:
                c += 1
            if s - goal in dic:
                c += dic[s - goal]
            if s in dic:
                dic[s] += 1
            else:
                dic[s] = 1
        return c
