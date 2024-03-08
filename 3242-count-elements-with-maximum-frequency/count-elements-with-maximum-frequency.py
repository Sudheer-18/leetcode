class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        dict={}
        for i in nums:
            if i not in dict:
                dict[i]=1
            else:
                dict[i]+=1
        maxi=0
        l=[]
        for i in dict:
            l.append(dict[i])
            maxi=max(maxi,dict[i])
        return l.count(maxi)*maxi

        