class Solution {
    public int maxAscendingSum(int[] nums) {
        int n = nums.length;
        int[] pre = new int[n];
        pre[0] = nums[0];
        int ans = pre[0];
        // System.out.print(pre[0]+" ");
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i]) {
                pre[i] = pre[i - 1] + nums[i];
            }
            else {
                pre[i] = nums[i];
            }
            ans = Math.max(ans,pre[i]);
            // System.out.print(pre[i]+" ");
        }
        return ans;
       

    }
}