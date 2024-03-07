class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v1;
        vector<int>v2;
        n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i>=nums.size()/2) v2.push_back(nums[i]);
            else v1.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<n/2;i++) {
            nums.push_back(v1[i]);
            nums.push_back(v2[i]);
        }
        return nums;
    }
};