class Solution {
public:
    string interpret(string s) {
        string str="";
        int i=0;
        while(i<s.length()) {
            if(s[i]=='(' && s[i+1]==')') {
                str+='o';
                i+=1;
            }
            else 
            {
                if(s[i]=='(' || s[i]==')') {
                     i+=1;
                }
                else {
                    str+=s[i];
                    i+=1;
                }
            }
        }
        return str;
    }
};