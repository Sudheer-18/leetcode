class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x < y:
            x, y = y, x
            pattern1, pattern2 = 'ba', 'ab'
        else:
            pattern1, pattern2 = 'ab', 'ba'
        
        points = 0
        stack = []
        
        # Process pattern1 ('ba') first
        for char in s:
            if stack and stack[-1] == pattern1[0] and char == pattern1[1]:
                stack.pop()
                points += x
            else:
                stack.append(char)
        
        # Process pattern2 ('ab') second
        temp_stack = []
        for char in stack:
            if temp_stack and temp_stack[-1] == pattern2[0] and char == pattern2[1]:
                temp_stack.pop()
                points += y
            else:
                temp_stack.append(char)
        
        return points