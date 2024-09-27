class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int[] pre_arr = new int[n];
        int i = 0;
        while (i < k) {
            int pre_sum = 0;
            int j = i;
            while (j < n) {
                pre_sum += energy[j];  
                j += k;   
            }
            pre_arr[i] = pre_sum;
            i++;
        }
        while (i < n) {
            pre_arr[i] = pre_arr[i - k] - energy[i - k];
            i++;
        }
        int ans = Integer.MIN_VALUE;
        for (int val : pre_arr) {
            ans = Math.max(ans, val);
        }
        
        return ans;
    }
}
