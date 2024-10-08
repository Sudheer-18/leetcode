class Solution {
    public int minSwaps(String s) {
        int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++) {
            char ch = s.charAt(i);
            if(ch == '[') res++;
            else if(res > 0) res--;
        }
        return (res+1)/2;
       
    }
}