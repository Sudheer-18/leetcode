class Solution {
public:
    int helper(vector<int>& nums,int curr,int idx) {
        if(idx == nums.size()) return curr;
        int pick = helper(nums,curr^nums[idx],idx+1);
        int unpick = helper(nums,curr,idx+1);
        return pick + unpick;
    }
    int subsetXORSum(vector<int>& nums) {
       
        return helper(nums,0,0);
       
    }
};