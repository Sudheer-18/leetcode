class Solution {
    public int countPartitions(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int[] pre = new int[n];
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        // 10 20 23 30 36
        int i = 0 ,j = n -1;
        int l = 0 ,r = 0;
        while(i < n - 1) {
            l  += pre[i];
            r = pre[j] -l;
            if( (r - l) % 2 == 0) ans++;
            i++;
        }

        return ans;
    }
}