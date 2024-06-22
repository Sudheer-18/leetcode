class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int oddCount = 0;
        int result = 0;
        int[] count = new int[nums.length + 1];
        count[0] = 1;
        
        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            if (oddCount >= k) {
                result += count[oddCount - k];
            }
            count[oddCount]++;
        }
        
        return result;
    }
}
