class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixXOR(n+1, 0); 
        for(int i = 0; i < n; i++) {
            prefixXOR[i+1] = prefixXOR[i] ^ nums[i];
        }
        vector<int> ans;
        for(auto q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(prefixXOR[r+1] ^ prefixXOR[l]);
        }

        return ans;
    }
};
