class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        k=start^goal
        return bin(k).count('1')
        