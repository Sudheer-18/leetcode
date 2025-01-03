class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long[] ps = new long[n];
        ps[0] =  nums[0];
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            ps[i] = ps[i - 1] + nums[i];
        }

        for (int i = 0; i < n - 1; i++) {
            if (ps[i] >= ps[n - 1] - ps[i]) ans++;
        }

        return ans;
    }
}
