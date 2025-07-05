class Solution {
    public int Helper(int[] dp,int n) {
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = Helper(dp,n-1) + Helper(dp,n-2);
    }
    public int climbStairs(int n) {
        int[] dp = new int[n+2];
       Arrays.fill(dp,-1);
        return Helper(dp,n);
    }
}