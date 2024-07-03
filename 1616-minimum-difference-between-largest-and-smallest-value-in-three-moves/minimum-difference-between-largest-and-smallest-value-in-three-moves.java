class Solution {
    public int minDifference(int[] nums) {
        Arrays.sort(nums);
        if(nums.length<=4) return  0;
        int ans = nums[nums.length-1]-nums[0];
        for(int i=0;i<4;i++) {
            ans = Math.min(ans,(nums[nums.length-1-i]-nums[3-i]));
        }
        return ans;
    }
}