class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        el=[]
        dic={}
        for i in nums:
            if i in dic:
                dic[i]+=1
            else:
                dic[i]=1
        for k,v in dic.items():
            if v==1:
                el.append(k)
        return el;
        