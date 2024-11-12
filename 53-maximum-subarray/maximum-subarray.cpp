class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
       int ans = nums[0];
       int sum = 0;
       for(int ele : nums) {
        if(sum < 0) sum = 0;
        sum+=ele;
        ans = max(ans,sum);
       }
       return ans;
    }
};