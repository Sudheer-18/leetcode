class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                cnt += nums[i-1]-nums[i]+1;
                nums[i]= nums[i-1]+1;
            }
        }
        return cnt;
    }
};