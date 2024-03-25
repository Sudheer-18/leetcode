class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        s=set()
        el=[]
        for i in nums:
            if i in s:
                el.append(i)
            else:
                s.add(i)
        return el

        