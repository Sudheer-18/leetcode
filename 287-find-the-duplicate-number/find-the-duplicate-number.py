class Solution(object):
    def findDuplicate(self, nums):

        nums.sort()
        
        length = len(nums)

        for i in range(1, length):
            if nums[i] == nums[i - 1]:
                return nums[i]
        return length