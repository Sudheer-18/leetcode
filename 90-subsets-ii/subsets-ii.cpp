class Solution {
public:
    vector<vector<int>> arr;
    void helper(vector<int>& nums,vector<int>& v,int ind,int size) {
        if(ind >= size) {
            arr.push_back(v); 
            return ;
        }
        v.push_back(nums[ind]);
        helper(nums,v,ind + 1,size);
        v.pop_back();
        int i = ind + 1;
        while(i < nums.size() && nums[i] == nums[ i - 1]) i++;
        helper(nums,v,i,size);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        sort(begin(nums),end(nums));
        helper(nums,v,0,n);
        return arr;
    }
};