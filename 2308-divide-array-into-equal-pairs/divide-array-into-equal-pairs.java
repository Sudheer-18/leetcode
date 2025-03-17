class Solution {
    public boolean divideArray(int[] nums) {
        int n = nums.length;
        if(n % 2 == 1) return false;
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i = 0; i < n; i++) {
            hm.put(nums[i],hm.getOrDefault(nums[i],0)+1);
        } 
        for(int i : hm.values()) {
            if(i % 2 == 1) return false;
        }

        return true;
    }
}