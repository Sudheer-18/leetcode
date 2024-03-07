class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        i=0;
        j=1;
        while(i<len(nums)-1):
            nums[i],nums[i+1]=nums[i+1],nums[i]
            i+=2;
            j+=2;
        return nums;
        