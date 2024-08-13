class Solution {
public:
    int tb(int n ,vector<int>& dp){
        if(n==0) return 0;
        if(n==1 || n ==2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = tb(n-1,dp)+tb(n-2,dp)+tb(n-3,dp);
    }
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n ==2) return 1;
        vector<int> dp(n+1,-1);
        tb(n,dp);
        return dp[n];
    }
};