class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int max = 0,cnt = 0,ans=0;
        for(int i=0;i<n;i++) {
            if(nums[i] > max) {
                max = nums[i];
                ans = 0;
                cnt = 1;
                ans = Math.max(ans,cnt);
            }
            else if(nums[i] == max) {
                cnt++;
                ans = Math.max(ans,cnt);
            }
            else cnt = 0;
        }
        return ans;
    } 
}