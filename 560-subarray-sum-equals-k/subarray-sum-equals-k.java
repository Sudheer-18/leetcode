class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0;
        mp.put(0, 1); 
        for (int x : nums) {
            sum += x;
            int fnd = sum - k;
            if (mp.containsKey(fnd)) {
                ans += mp.get(fnd);  
            }
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);  
        }

        return ans;
    }
}
