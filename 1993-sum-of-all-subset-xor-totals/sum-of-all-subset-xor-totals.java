class Solution {
    public int Recur(int[] nums,int idx, int curr) {
        if(idx >= nums.length) return curr;
        int P = Recur(nums,idx+1,curr^nums[idx]);
        int UP = Recur(nums,idx+1,curr);
        return P+UP;
    }
    public int subsetXORSum(int[] nums) {
        return Recur(nums,0,0);
    }
}