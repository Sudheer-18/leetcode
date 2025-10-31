class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int x : nums) mp[x]++;
        for(auto it : mp) {
            if(it.second == 2) ans.emplace_back(it.first);
        }
        return ans;
    }
};