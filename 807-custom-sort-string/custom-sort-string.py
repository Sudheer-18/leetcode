class Solution:
    def customSortString(self, o: str, s: str) -> str:
        return ''.join(sorted(s,key=o.find))