class Solution:
    def subarraysDivByK(self, lst: List[int], k: int) -> int:
        dic = {0: 1}
        s = 0
        cnt = 0
        n = len(lst)
        for i in range(n):
            s = (s + lst[i]) % k
            if s in dic:
                cnt += dic[s]
                dic[s] += 1
            else:
                dic[s] = 1 
        return cnt
