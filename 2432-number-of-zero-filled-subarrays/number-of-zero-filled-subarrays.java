class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long cnt = 0, curr = 0;
        for (int x : nums) {
            curr = (x == 0) ? curr + 1 : 0;
            cnt += curr;
        }
        return cnt;
    }
}