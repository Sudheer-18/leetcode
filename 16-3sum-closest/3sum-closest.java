class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int clos_sum = nums[0] + nums[1] + nums[2]; 
        int n = nums.length;
        for (int i = 0; i < n - 2; i++) {
            int s = i + 1, e = n - 1;
            while (s < e) {
                int curr_sum = nums[i] + nums[s] + nums[e];
                if (Math.abs(curr_sum - target) < Math.abs(clos_sum - target)) {
                    clos_sum = curr_sum;
                }
                if (curr_sum < target) {
                    s++;
                } 
                else if (curr_sum > target) {
                    e--;
                }
                 else {
                    return curr_sum;
                }
            }
        }
        return clos_sum;
    }
}
