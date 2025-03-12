class Solution {
    public int maximumCount(int[] nums) {
        int PosCnt = 0 , NegCnt = 0 , MaxCnt = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 0) continue;
            if(nums[i] < 0) {
                NegCnt++;
            }
            else {
                PosCnt++;
            }
            MaxCnt = Math.max(PosCnt,NegCnt);
        }

        return MaxCnt;
    }
}