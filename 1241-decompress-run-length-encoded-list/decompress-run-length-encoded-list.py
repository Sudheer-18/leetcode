class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        d= []
        for i in range(len(nums)//2):
            frequency = nums[2*i]
            value = nums[2*i+1]
            d+= [value]*frequency
        return d