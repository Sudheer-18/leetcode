class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        arr = list(word)
        if ch in word:
            k = arr.index(ch)
            arr[:k+1] = arr[:k+1][::-1]
            return ''.join(arr)
        return word
