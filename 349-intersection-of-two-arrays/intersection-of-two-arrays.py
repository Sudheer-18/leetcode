class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c=[]
        nums1=set(nums1)
        nums2=set(nums2)
        c=nums1.intersection(nums2)
        return c;
        