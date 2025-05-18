class Solution {
    public int smallestIndex(int[] nums) {
        int MinVal = Integer.MAX_VALUE;
        for(int i=0; i<nums.length; i++) {
            int sum = DigitSum(nums[i]);
            if(sum == i) {
                MinVal = Math.min(MinVal,sum);
            }
        }  
        if(MinVal == Integer.MAX_VALUE) return -1;
        return MinVal;
    }
    public static int DigitSum(int num) {
        int r,s=0;
        while(num != 0) {
            r = num % 10;
            s += r;
            num/=10;
        }
        return s;
    }
}