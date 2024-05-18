class Solution {
public:
    string removeStars(string s) {
       stack<char>st;
       int i=0;
       string str="";
       while(i<s.size()) 
       {
        if(isalpha(s[i])) 
        {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
        i+=1;
       }
       while(! st.empty()) 
       {
         str+=st.top();
         st.pop();
       }
       i=0;
       int j=str.size()-1;
       while(i<j) 
       {
        swap(str[i],str[j]);
        i+=1;
        j-=1;
       }
       return str;
    }
};