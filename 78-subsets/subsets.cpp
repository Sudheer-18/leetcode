class Solution {
public:
    vector<vector<int>> arr;
    void helper(vector<int>& nums,vector<int>& v,int i, int n) {
        if(i >= n) {
            arr.push_back(v);
            return ;
        }
        v.push_back(nums[i]);
        helper(nums,v,i + 1, n);
        v.pop_back();
        helper(nums,v,i + 1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        helper(nums,v,0, n);
        return arr;
    }
};