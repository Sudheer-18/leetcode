class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int[] ans = new int[n];
        int r_sum = 0;        
        for(int i = 0; i < m; i++) {
            r_sum += rolls[i];
        }        
        int t_sum = (n + m) * mean;        
        int missing_sum = t_sum - r_sum;        
        if(missing_sum < n || missing_sum > 6 * n) {
            return new int[0]; 
        }
        Arrays.fill(ans, 1);
        missing_sum -= n;
        for(int i = 0; i < n; i++) {
            int add = Math.min(5, missing_sum);
            ans[i] += add;
            missing_sum -= add;
            if(missing_sum == 0) {
                break; 
            }
        }
        
        return ans;
    }
}
