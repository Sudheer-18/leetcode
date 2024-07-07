class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        s=f=1
        while time:
            time-=1
            if f:
                s+=1
                if s==n:
                    f = not f
            else:
                s-=1
                if s==1:
                    f = not f
        return s
        