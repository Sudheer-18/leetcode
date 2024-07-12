class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x < y:
            x, y = y, x
            pattern1, pattern2 = 'ba', 'ab'
        else:
            pattern1, pattern2 = 'ab', 'ba'
        
        def remove_pattern_and_score(s, pattern, score):
            stack = []
            points = 0
            for char in s:
                if stack and stack[-1] == pattern[0] and char == pattern[1]:
                    stack.pop()
                    points += score
                else:
                    stack.append(char)
            return ''.join(stack), points
        
        # First, remove and score the more valuable pattern
        remaining_string, points = remove_pattern_and_score(s, pattern1, x)
        
        # Then, remove and score the less valuable pattern
        _, additional_points = remove_pattern_and_score(remaining_string, pattern2, y)
        
        return points + additional_points
