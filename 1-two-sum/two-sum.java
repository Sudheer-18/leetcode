class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> hs = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (hs.containsKey(target - num)) {
                return new int[] { i, hs.get(target - num) };
            }
            hs.put(num, i);
        }

        return new int[] {};        
    }
}