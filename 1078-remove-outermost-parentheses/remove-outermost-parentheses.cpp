class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int openCount = 0;  // To keep track of the balance of parentheses
        
        for(char ch : s) {
            if (ch == '(') {
                if (openCount > 0) {  // Only add '(' if it's not the outermost
                    result += ch;
                }
                openCount++;
            } else if (ch == ')') {
                openCount--;
                if (openCount > 0) {  // Only add ')' if it's not the outermost
                    result += ch;
                }
            }
        }
        
        return result;
    }
};
