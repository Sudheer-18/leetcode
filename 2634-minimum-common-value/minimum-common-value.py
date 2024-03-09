from typing import List

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        common_elements = set(nums1) & set(nums2)
        if not common_elements:
            return -1 
        return min(common_elements)
