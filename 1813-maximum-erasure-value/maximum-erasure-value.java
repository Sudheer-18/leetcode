class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        HashSet<Integer> hs = new HashSet<>();
        int sum = 0, ans = 0;
        while (j < n) {
            while (hs.contains(nums[j])) {
                hs.remove(nums[i]);
                sum -= nums[i];
                i++;
            }
            hs.add(nums[j]);
            sum += nums[j];
            ans = Math.max(ans, sum);
            j++;
        }

        return ans;
    }
}
