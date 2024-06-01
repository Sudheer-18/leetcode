class Solution {
public:
    int scoreOfString(string s) {
        int s1=0;
        for(int i=0;i<s.length()-1;i++) {
             int a1 = static_cast<int>(s[i]);
             int a2 = static_cast<int>(s[i+1]);
             s1+=abs(a1-a2);
        }
        return s1;
    }
};