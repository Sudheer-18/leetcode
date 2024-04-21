class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()  
        def sort_key(word):
            return int(word[-1])
        
        words.sort(key=sort_key) 

        sorted_words = [word[:-1] for word in words]
        return ' '.join(sorted_words)
