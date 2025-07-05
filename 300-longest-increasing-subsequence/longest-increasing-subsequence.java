class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp,1);
        int maxi = 0;
         if(n == 1) return 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j])
                    dp[i] = Math.max(dp[i],dp[j]+1);
            }
            maxi = Math.max(maxi,dp[i]);
        }
        return maxi;
    }
}