class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0, ind = 26;
        for(int i=0; i<n; i++) {
            ans += (('z'-s[i]+1) * (i+1));
            ind--;
        }
        return ans;
    }
};