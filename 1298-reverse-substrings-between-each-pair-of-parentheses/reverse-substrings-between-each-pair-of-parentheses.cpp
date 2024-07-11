class Solution {
public:
    // string reverse(String s) {
    //     int i=0,j=s.length()-1;
    //     while(i<j) {
    //         swap(s[i],s[j]);
    //         i+=1;
    //         j-=1;
    //     }
    //     return s;
    // }
    string reverseParentheses(string s) {
        stack<int> st;
        string rev= "";
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                 st.push(i);
            }
            else if(s[i]==')') {
                int start = st.top()+1;
                int end = i;
                reverse(s.begin()+start,s.begin()+end);
                st.pop();
            }
        }
        for(int i=0;i<n;i++) {
            if(s[i]!= '(' && s[i]!=')') rev+=s[i];
        }
        return rev;
    }
};