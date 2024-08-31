class Solution {
    public int combinationSum4(int[] nums, int target) {
        ArrayList<Integer> dp = new ArrayList<>(Collections.nCopies(target + 1, -1));
        return helper(nums, target, dp);
    }

    public int helper(int[] nums, int target, ArrayList<Integer> dp) {
        if (target == 0) {
            return 1; 
        }
        if (target < 0) {
            return 0; 
        }
        if (dp.get(target) != -1) {
            return dp.get(target); 
        }

        int result = 0;
        for (int num : nums) {
            result += helper(nums, target - num, dp);
        }

        dp.set(target, result); 
        return result;
    }
}
