class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s1 = s1.split(' ')
        s2 = s2.split(' ')
        dic = {}
        ans = []
        for i in s1:
            if i in dic:
                dic[i]+=1
            else:
                dic[i] = 1
        for i in s2:
            if i in dic:
                dic[i]+=1
            else:
                dic[i] = 1
        for k,v in dic.items():
            if v == 1:
                ans.append(k)
        return ans



        