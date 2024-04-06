#include <string>
#include <stack>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::stack<int> st;
        
        // Mark invalid parentheses for removal
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*'; // Mark ')' for removal
                }
            }
        }
        
        // Mark remaining '(' for removal
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        // Remove marked characters
        s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
};
