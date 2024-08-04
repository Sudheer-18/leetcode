class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int i = 0, j = 0, k = 0;
        int size = (n * (n + 1)) / 2;
        int[] arr = new int[size];
        int pre_sum = 0;
        
        while (i < n) {
            if (j == n) {
                i += 1;
                j = i;
                pre_sum = 0;
                if (i >= n) break;
            }
            pre_sum += nums[j];
            arr[k] = pre_sum;
            j += 1;
            k += 1;
        }
        
        Arrays.sort(arr);
        int ans = 0;
        for (i = left - 1; i < right; i++) {
            ans = (ans + arr[i]) % 1000000007;
        } 
        return ans;
    }
}
