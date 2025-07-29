class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] DP = new int[n];
        DP[0] = cost[0];
        DP[1] = cost[1];
        for(int i = 2; i < n; i++) {
            DP[i] = cost[i] + Math.min(DP[i-1],DP[i-2]);
        }

        return Math.min(DP[n-1],DP[n-2]);
    }
}