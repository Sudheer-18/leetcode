class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        # Split the sentence into words
        words = sentence.split(' ')
        
        # Sort dictionary roots by length to ensure the shortest replacement
        dictionary.sort(key=len)
        
        # Replace words with roots
        for i in range(len(words)):
            for root in dictionary:
                if words[i].startswith(root):
                    words[i] = root
                    break
        
        # Join the modified words back into a sentence with spaces
        return ' '.join(words)
