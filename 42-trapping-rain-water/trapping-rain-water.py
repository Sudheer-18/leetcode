class Solution(object):
    def trap(self, h):
        """
        :type height: List[int]
        :rtype: int
        """
        l=[]
        r=[]
        s=0
        m1=0
        for i in range(len(h)-1):
            if m1>h[i]:
                l.append(m1)
            else:
                l.append(h[i])
                m1=h[i]
        m2=0
        for i in range(len(h)-1,-1,-1):
            if m2>h[i]:
                r.append(m2)
            else:
                r.append(h[i])
                m2=h[i]
        r.reverse()
        for i in range(len(h)-1):
            k=min(l[i],r[i])
            d=k-h[i]
            s+=d
        return s

                