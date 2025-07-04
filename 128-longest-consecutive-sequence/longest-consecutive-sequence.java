class Solution {
    public int longestConsecutive(int[] nums) {
        int ans = 0;
        int n = nums.length;
        Set<Integer> hs = new HashSet<>();
        for(int x : nums) hs.add(x);
        for(int x : hs) {
            if(!hs.contains(x-1)) {
                int len = 1;
                while(hs.contains(x+len)) len++;
                ans = Math.max(ans,len);
            }
        }

        return ans;
    }
}