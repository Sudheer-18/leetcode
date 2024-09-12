class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        dc= c=0
        for i in words:
            c=0
            for j in i:
                if j in allowed:
                    c+=1
            if len(i)==c:
                dc+=1
        return dc
        