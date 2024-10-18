class Solution {
public:
    vector<int> arr; 
    void help(vector<int>& nums, int ind, int n, vector<int>& v) {
        if (ind >= n) return; 
        v.push_back(nums[ind]);
        int ans = v[0];
        for (int i = 1; i < v.size(); i++) {
            ans |= v[i];
        }
        arr.push_back(ans);
        help(nums, ind + 1, n, v);  
        v.pop_back();               
        help(nums, ind + 1, n, v); 
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        help(nums, 0, n, v); 
        int max_val = *max_element(arr.begin(), arr.end());  
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == max_val) ans++;  
        }
        return ans;
    }
};
