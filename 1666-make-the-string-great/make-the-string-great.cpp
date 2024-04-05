#include <stack>
#include <string>
#include <cmath>

class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        
        for (char c : s) {
            if (!stk.empty() && abs(stk.top() - c) == 32) { // Check if the current character and the top of the stack are same letter but different cases
                stk.pop(); // Pop the character from the stack
            } else {
                stk.push(c); // Push the character onto the stack
            }
        }
        
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result; // Construct the result string in reverse order
            stk.pop();
        }
        
        return result;
    }
};
