class Solution {
    public int minCapability(int[] nums, int k) {
        int n = nums.length;
        int low = 1 , high = 0;
        for(int i = 0; i < n ;i++) {
            if(high < nums[i]) {
                high = nums[i];
            }
        }
        while(low < high) {
            int mid = (low + high) / 2;
            int rc = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] <= mid) {
                    rc++;
                    i++;
                }
            }
            if(rc >= k) {
                high = mid;
            }
            else low = mid + 1;
        } 

        return low;
    }
}