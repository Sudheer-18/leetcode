class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(char ch : s) {
            if(ch == ']' && st.empty()) continue;
            else if(ch == ']' && st.top() == '[') st.pop();
            else st.push('[');
        }
        return (st.size()+1)/2;
    }
};