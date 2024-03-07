class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n=len(nums)
        s=0;
        for i in range(n):
            for j in range(i,n):
                k=len(set(nums[i:j+1]))
                s+=(k**2);
        return s
        