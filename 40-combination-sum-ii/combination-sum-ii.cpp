class Solution {
public:
    void recursion(vector<int>& nums, int tar, int size, int ind, int sum, vector<vector<int>>& ans, vector<int>& v1) {
        if (sum == tar) {
            ans.push_back(v1);
            return;
        }
        if (sum > tar || ind >= size) return;
        
        for (int i = ind; i < size; ++i) {
            if (i > ind && nums[i] == nums[i-1]) continue;  // Skip duplicates
            v1.push_back(nums[i]);
            recursion(nums, tar, size, i + 1, sum + nums[i], ans, v1);
            v1.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());  // Sort the input to handle duplicates
        recursion(nums, tar, nums.size(), 0, 0, ans, res);
        return ans;
    }
};
