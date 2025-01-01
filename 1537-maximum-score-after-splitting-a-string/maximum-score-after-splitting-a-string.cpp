class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n  = s.size();
        int oc =  0;
        for(char ch : s) {
            if(ch == '1') oc++;
        }
        int zc = 0, mc = 0;
        for(int i = 0;i < n - 1;i++) {
            if(s[i] == '0') zc++;
            else oc--;
            mc = max(mc,oc+zc);
        }
        return mc;
    } 
};