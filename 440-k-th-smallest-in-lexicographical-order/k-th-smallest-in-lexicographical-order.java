class Solution {
    public int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; 
        while (k > 0) {
            int stp = cntstp(n, curr, curr + 1);
            if (stp <= k) {
                curr += 1;
                k -= stp;
            } 
            else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
    private int cntstp(int n, long curr, long next) {
        int stp = 0;
        while (curr <= n) {
            stp += Math.min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return stp;
    }
}
