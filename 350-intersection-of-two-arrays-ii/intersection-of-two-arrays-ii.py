from typing import List

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic1 = {}
        dic2 = {}
        arr = []
        for i in nums1:
            if i in dic1:
                dic1[i] += 1
            else:
                dic1[i] = 1
        for i in nums2:
            if i in dic2:
                dic2[i] += 1
            else:
                dic2[i] = 1
        for k, v in dic1.items():
            if k in dic2:
                arr.extend([k] * min(v, dic2[k]))
        
        return arr
