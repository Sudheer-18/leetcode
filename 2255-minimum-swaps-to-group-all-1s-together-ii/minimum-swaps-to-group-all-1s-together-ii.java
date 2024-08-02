class Solution {
    public int minSwaps(int[] nums) {
        int ones_cnt = 0;
        int n = nums.length;
        int[] arr = new int[2*n];
        for(int i=0;i<2*n;i++) {
            arr[i] = nums[i%n];
        }
        for(int i=0;i<n;i++){
            if(nums[i] == 1) ones_cnt+=1;
        }
        int i=0,j=0;
        int curr_ones = 0,max_cnt =0;
        while(j < 2*n) {
            if(arr[j] == 1) {
                curr_ones+=1;
            }
            if(j-i+1 > ones_cnt) {
                curr_ones-=arr[i];
                i+=1;
            }
            max_cnt = Math.max(max_cnt,curr_ones);
            j++;
        }
        return ones_cnt - max_cnt;
       
    }
}