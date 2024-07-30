class Solution {
    public int minimumDeletions(String s) {
        // Stack<Integer> st = new Stack<>();
        int ans = 0,cnt = 0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == 'b') cnt+=1;
            else  ans = Math.min(ans+1,cnt);
        }
        return ans;
    }
}