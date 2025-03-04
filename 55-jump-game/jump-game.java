class Solution {

    public boolean canJump(int[] nums) {
        int n = nums.length;
        // int[] DP = new int[n+1];
        int CanReach = 0;
        for(int i = 0; i < n; i++) {
            if(i > CanReach) return false;
            CanReach = Math.max(CanReach,i+nums[i]);
        }
        return true;
    }
}