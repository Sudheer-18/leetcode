class Solution:
    def isCircularSentence(self, s: str) -> bool:
        n = len(s)
        arr = []
        arr = s.split(' ')
        fo = arr[0]
        lo = arr[len(arr)-1]
        for i in range(len(arr)-1):
            s1 = arr[i]
            s2 = arr[i+1]
            if(s1[-1] != s2[0]):
                return  False
        if(fo[0] != lo[-1]):
            return False
        return True


