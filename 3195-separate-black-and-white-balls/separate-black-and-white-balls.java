class Solution {
    public long minimumSteps(String s) {
        long ans = 0;
        int w = 0;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if(s.charAt(i) == '0') ans+=w;
            else w++;
        }
        return ans;
    }
}