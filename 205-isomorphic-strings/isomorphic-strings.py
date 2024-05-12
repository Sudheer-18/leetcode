class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        mapping_s = {}
        mapping_t = {}

        for i in range(len(s)):
            if s[i] not in mapping_s:
                mapping_s[s[i]] = t[i]
            elif mapping_s[s[i]] != t[i]:
                return False

            if t[i] not in mapping_t:
                mapping_t[t[i]] = s[i]
            elif mapping_t[t[i]] != s[i]:
                return False

        return True
